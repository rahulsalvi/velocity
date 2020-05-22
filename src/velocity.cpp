#include <iostream>
#include <memory>

#include "EndSegment.h"
#include "OutputGenerator.h"
#include "RGBColor.h"
#include "ResetColor.h"
#include "StartSegment.h"
#include "TermColor.h"
#include "TextSegment.h"

using std::cout;
using std::endl;
using std::make_shared;

int main() {
    auto rgb_red    = make_shared<RGBColor>(255, 0, 0);
    auto term_cyan  = make_shared<TermColor>("cyan");
    auto term_black = make_shared<TermColor>("black");
    auto rgb_purple = make_shared<RGBColor>(255, 0, 255);

    auto start = make_shared<StartSegment>();
    auto t     = make_shared<TextSegment>(Format(rgb_red, term_cyan), "hello world", "", 0);
    auto t2    = make_shared<TextSegment>(Format(term_black, rgb_purple), "foo", "", 0);
    auto end   = make_shared<EndSegment>();

    start->set_next(t);
    t->set_prev(start);
    t->set_next(t2);
    t2->set_prev(t);
    t2->set_next(end);
    end->set_prev(t2);

    OutputGenerator p;
    start->accept(p);
    cout << p.text();
    return 0;
}
