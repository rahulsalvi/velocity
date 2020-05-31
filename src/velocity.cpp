#include <iostream>
#include <memory>

#include "Format.h"
#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "color/TermColor256.h"
#include "color/visitor/ANSIColorCodeGenerator.h"
#include "color/visitor/ZshColorCodeGenerator.h"
#include "segment/CWDSegment.h"
#include "segment/EndSegment.h"
#include "segment/EnvironmentConditionalSegment.h"
#include "segment/GitInfoSegment.h"
#include "segment/GitRepoConditionalSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/EvalVisitor.h"
#include "segment/visitor/ForwardGenerator.h"
#include "segment/visitor/ReverseGenerator.h"
#include "style/BoldStyle.h"
#include "style/DoubleUnderlineStyle.h"
#include "style/FaintStyle.h"
#include "style/ItalicStyle.h"
#include "style/ResetStyle.h"
#include "style/StrikethroughStyle.h"
#include "style/UnderlineStyle.h"
#include "style/visitor/ANSIStyleCodeGenerator.h"
#include "style/visitor/ZshStyleCodeGenerator.h"

using std::cerr;
using std::cout;
using std::endl;
using std::make_shared;
using velocity::color::ANSIColorCodeGenerator;
using velocity::color::RGBColor;
using velocity::color::TermColor;
using velocity::color::TermColor256;
using velocity::color::ZshColorCodeGenerator;
using velocity::segment::CWDSegment;
using velocity::segment::EndSegment;
using velocity::segment::EnvironmentConditionalSegment;
using velocity::segment::EvalVisitor;
using velocity::segment::ForwardGenerator;
using velocity::segment::GitInfoSegment;
using velocity::segment::GitRepoConditionalSegment;
using velocity::segment::ReverseGenerator;
using velocity::segment::StartSegment;
using velocity::segment::TextSegment;
using velocity::style::ANSIStyleCodeGenerator;
using velocity::style::BoldStyle;
using velocity::style::DoubleUnderlineStyle;
using velocity::style::FaintStyle;
using velocity::style::ItalicStyle;
using velocity::style::ResetStyle;
using velocity::style::StrikethroughStyle;
using velocity::style::UnderlineStyle;
using velocity::style::ZshStyleCodeGenerator;

#include <chrono>

auto term_brcyan = make_shared<TermColor>("brcyan");
auto term_black  = make_shared<TermColor>("black");
auto term_blue   = make_shared<TermColor>("blue");
auto term_green  = make_shared<TermColor>("green");
auto term_yellow = make_shared<TermColor>("yellow");
auto term_red    = make_shared<TermColor>("red");

auto term_42 = make_shared<TermColor256>(42);

auto bold_style             = make_shared<BoldStyle>();
auto faint_style            = make_shared<FaintStyle>();
auto italic_style           = make_shared<ItalicStyle>();
auto underline_style        = make_shared<UnderlineStyle>();
auto double_underline_style = make_shared<DoubleUnderlineStyle>();
auto strikethrough_style    = make_shared<StrikethroughStyle>();
auto reset_style            = make_shared<ResetStyle>();

auto ansi_color_code_generator = make_shared<ANSIColorCodeGenerator>();
auto ansi_style_code_generator = make_shared<ANSIStyleCodeGenerator>();

auto zsh_color_code_generator = make_shared<ZshColorCodeGenerator>();
auto zsh_style_code_generator = make_shared<ZshStyleCodeGenerator>();

void prompt_forward() {
    auto start = make_shared<StartSegment>();
    auto env_test =
        make_shared<EnvironmentConditionalSegment>("TEST1", "", velocity::segment::NOT_EQUALS);
    auto env_test2 =
        make_shared<EnvironmentConditionalSegment>("TEST2", "foo", velocity::segment::EQUALS);
    auto hostinfo = make_shared<TextSegment>(
        Format(term_black, term_brcyan, {}), 0, "${USERNAME}@${HOST}", "");
    auto cwd         = make_shared<CWDSegment>(Format(term_black, term_blue, {}), 0, "", "");
    auto in_git_repo = make_shared<GitRepoConditionalSegment>();
    auto git         = make_shared<GitInfoSegment>(Format(term_black, term_green, {}),
                                           Format(term_black, term_yellow, {}),
                                           Format(term_black, term_red, {}),
                                           0,
                                           "➦",
                                           "",
                                           "±",
                                           "");
    auto end         = make_shared<EndSegment>();

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

    /* ForwardGenerator p(ansi_color_code_generator, ansi_style_code_generator); */
    ForwardGenerator p(zsh_color_code_generator, zsh_style_code_generator);

    start->accept(p);
    cout << p.text();
}

void prompt_reverse() {
    auto start    = make_shared<StartSegment>();
    auto hostinfo = make_shared<TextSegment>(
        Format(term_black, term_brcyan, {strikethrough_style, italic_style}),
        "${USERNAME}@${HOST}",
        "",
        0);
    auto cwd = make_shared<CWDSegment>(Format(term_black, term_blue, {bold_style}), 0, "", "");
    auto in_git_repo = make_shared<GitRepoConditionalSegment>();
    auto git         = make_shared<GitInfoSegment>(Format(term_black, term_green, {}),
                                           Format(term_black, term_yellow, {}),
                                           Format(term_black, term_red, {}),
                                           "➦",
                                           "",
                                           "±",
                                           "",
                                           0);
    auto end         = make_shared<EndSegment>();

    start->set_next(hostinfo);
    hostinfo->set_prev(start);
    hostinfo->set_next(cwd);
    cwd->set_prev(hostinfo);
    cwd->set_next(in_git_repo);
    in_git_repo->set_prev(cwd);
    in_git_repo->set_next(git);
    git->set_prev(in_git_repo);
    git->set_next(end);
    end->set_prev(end);

    in_git_repo->set_true_segment(git);
    in_git_repo->set_false_segment(end);

    EvalVisitor e;
    start->accept(e);

    ReverseGenerator p(ansi_color_code_generator, ansi_style_code_generator);
    /* ReverseGenerator p(zsh_color_code_generator, zsh_style_code_generator); */

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
