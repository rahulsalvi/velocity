#include <iostream>
#include <memory>

#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
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
using velocity::segment::EndSegment;
using velocity::segment::StartSegment;
using velocity::segment::TextSegment;
using velocity::zsh::ForwardGenerator;
using velocity::zsh::ReverseGenerator;

#include <chrono>

int main() {
    auto a = std::chrono::high_resolution_clock::now();

    auto rgb_red    = make_shared<RGBColor>(255, 0, 0);
    auto term_cyan  = make_shared<TermColor>("cyan");
    auto term_black = make_shared<TermColor>("black");
    auto rgb_purple = make_shared<RGBColor>(255, 0, 255);

    auto start = make_shared<StartSegment>();
    auto t1    = make_shared<TextSegment>(Format(rgb_red, term_cyan), "hello world", "", 0);
    auto t2    = make_shared<TextSegment>(Format(term_black, rgb_purple), "foo", "", 0);
    auto end   = make_shared<EndSegment>();

    start->set_next(t1);
    t1->set_prev(start);
    t1->set_next(t2);
    t2->set_prev(t1);
    t2->set_next(end);
    end->set_prev(t2);

    ForwardGenerator p;
    start->accept(p);
    cout << p.text() << endl;

    auto b = std::chrono::high_resolution_clock::now();

    double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(b - a).count();
    cout << time_taken << " us" << endl;

    auto t3 = make_shared<TextSegment>(Format(rgb_red, term_cyan), "hello world", "", 0);
    auto t4 = make_shared<TextSegment>(Format(term_black, rgb_purple), "foo", "", 0);

    start->set_next(t3);
    t3->set_prev(start);
    t3->set_next(t4);
    t4->set_prev(t3);
    t4->set_next(end);
    end->set_prev(t4);

    ReverseGenerator p2;
    start->accept(p2);
    cout << p2.text() << endl;
    return 0;
}
