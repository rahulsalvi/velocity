#include <iostream>
#include <memory>

#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "segment/CWDSegment.h"
#include "segment/EndSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "zsh/ForwardGenerator.h"
#include "zsh/ReverseGenerator.h"

using std::cout;
using std::endl;
using std::make_shared;
using velocity::color::RGBColor;
using velocity::color::TermColor;
using velocity::segment::CWDSegment;
using velocity::segment::EndSegment;
using velocity::segment::StartSegment;
using velocity::segment::TextSegment;
using velocity::zsh::ForwardGenerator;
using velocity::zsh::ReverseGenerator;

#include <chrono>

void prompt_forward() {
    auto term_brcyan = make_shared<TermColor>("brcyan");
    auto term_black  = make_shared<TermColor>("black");
    auto term_blue   = make_shared<TermColor>("blue");

    auto start = make_shared<StartSegment>();
    auto hostinfo =
        make_shared<TextSegment>(Format(term_black, term_brcyan), "${USERNAME}@${HOST}", "", 0);
    auto cwd = make_shared<CWDSegment>(Format(term_black, term_blue), "", "", 0);
    auto end = make_shared<EndSegment>();

    start->set_next(hostinfo);
    hostinfo->set_prev(start);
    hostinfo->set_next(cwd);
    cwd->set_prev(hostinfo);
    cwd->set_next(end);
    end->set_prev(cwd);

    cwd->eval();

    ForwardGenerator p;
    start->accept(p);
    cout << p.text();
}

void prompt_reverse() {
    auto term_brcyan = make_shared<TermColor>("brcyan");
    auto term_black  = make_shared<TermColor>("black");
    auto term_blue   = make_shared<TermColor>("blue");

    auto start = make_shared<StartSegment>();
    auto hostinfo =
        make_shared<TextSegment>(Format(term_black, term_brcyan), "${USERNAME}@${HOST}", "", 0);
    auto cwd = make_shared<CWDSegment>(Format(term_black, term_blue), "", "", 0);
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
    /* auto a = std::chrono::high_resolution_clock::now(); */

    prompt_forward();
    /* prompt_reverse(); */

    /* auto   b          = std::chrono::high_resolution_clock::now(); */
    /* double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(b - a).count(); */
    /* cout << time_taken << " us" << endl; */
    return 0;
}
