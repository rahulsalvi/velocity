#include "TermColor.h"

using std::to_string;

TermColor::TermColor(string color) {
    foreground_ = color2code.at(color);
    background_ = foreground_ + 10;
}

TermColor::~TermColor() {}

string TermColor::ansi_code_foreground() const {
    return "\e[" + to_string(foreground_) + "m";
}

string TermColor::ansi_code_background() const {
    return "\e[" + to_string(background_) + "m";
}
