#include <iostream>
#include <memory>

#include "Format.h"
#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "segment/CWDSegment.h"
#include "segment/EndSegment.h"
#include "segment/EnvironmentConditionalSegment.h"
#include "segment/GitRepoConditionalSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/EvalVisitor.h"
#include "style/BoldStyle.h"
#include "style/NormalStyle.h"
#include "zsh/ForwardGenerator.h"
#include "zsh/ReverseGenerator.h"

using std::cerr;
using std::cout;
using std::endl;
using std::make_shared;
using velocity::color::RGBColor;
using velocity::color::TermColor;
using velocity::segment::CWDSegment;
using velocity::segment::EndSegment;
using velocity::segment::EnvironmentConditionalSegment;
using velocity::segment::EvalVisitor;
using velocity::segment::GitRepoConditionalSegment;
using velocity::segment::StartSegment;
using velocity::segment::TextSegment;
using velocity::style::BoldStyle;
using velocity::style::NormalStyle;
using velocity::zsh::ForwardGenerator;
using velocity::zsh::ReverseGenerator;

#include <chrono>

void prompt_forward() {
    auto term_brcyan = make_shared<TermColor>("brcyan");
    auto term_black  = make_shared<TermColor>("black");
    auto term_blue   = make_shared<TermColor>("blue");
    auto term_green  = make_shared<TermColor>("green");
    auto normal      = make_shared<NormalStyle>();
    auto bold        = make_shared<BoldStyle>();

    auto start = make_shared<StartSegment>();
    auto env_test =
        make_shared<EnvironmentConditionalSegment>("TEST1", "", velocity::segment::NOT_EQUALS);
    auto env_test2 =
        make_shared<EnvironmentConditionalSegment>("TEST2", "foo", velocity::segment::EQUALS);
    auto hostinfo = make_shared<TextSegment>(
        Format(term_black, term_brcyan, normal), "${USERNAME}@${HOST}", "", 0);
    auto cwd = make_shared<CWDSegment>(Format(term_black, term_blue, normal), "", "", 0);
    auto in_git_repo = make_shared<GitRepoConditionalSegment>();
    auto git = make_shared<TextSegment>(Format(term_black, term_green, bold), "GIT", "", 0);
    auto end = make_shared<EndSegment>();

    // AND
    /* env_test->set_true_segment(env_test2); */
    /* env_test->set_false_segment(cwd); */
    /* env_test2->set_true_segment(hostinfo); */
    /* env_test2->set_false_segment(cwd); */

    // OR
    env_test->set_true_segment(hostinfo);
    env_test->set_false_segment(env_test2);
    env_test2->set_true_segment(hostinfo);
    env_test2->set_false_segment(cwd);

    in_git_repo->set_true_segment(git);
    in_git_repo->set_false_segment(end);

    start->set_next(env_test);
    env_test->set_prev(start);
    env_test->set_next(env_test2);
    env_test2->set_prev(env_test);
    env_test2->set_next(hostinfo);
    hostinfo->set_prev(env_test2);
    hostinfo->set_next(cwd);
    cwd->set_prev(hostinfo);
    cwd->set_next(in_git_repo);
    in_git_repo->set_prev(cwd);
    in_git_repo->set_next(git);
    git->set_prev(in_git_repo);
    git->set_next(end);
    end->set_prev(end);

    EvalVisitor e;
    start->accept(e);

    ForwardGenerator p;
    start->accept(p);
    cout << p.text();
}

void prompt_reverse() {
    auto term_brcyan = make_shared<TermColor>("brcyan");
    auto term_black  = make_shared<TermColor>("black");
    auto term_blue   = make_shared<TermColor>("blue");
    auto normal      = make_shared<NormalStyle>();

    auto start    = make_shared<StartSegment>();
    auto hostinfo = make_shared<TextSegment>(
        Format(term_black, term_brcyan, normal), "${USERNAME}@${HOST}", "", 0);
    auto cwd = make_shared<CWDSegment>(Format(term_black, term_blue, normal), "", "", 0);
    auto end = make_shared<EndSegment>();

    start->set_next(hostinfo);
    hostinfo->set_prev(start);
    hostinfo->set_next(cwd);
    cwd->set_prev(hostinfo);
    cwd->set_next(end);
    end->set_prev(cwd);

    cwd->eval();

    ReverseGenerator p;
    start->accept(p);
    cout << p.text();
}

int main() {
    auto a = std::chrono::high_resolution_clock::now();

    prompt_forward();
    /* prompt_reverse(); */

    auto   b          = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(b - a).count();
    cerr << time_taken << " us" << endl;
    return 0;
}
