#include "RGBColor.h"

using std::to_string;

RGBColor::RGBColor(uint8_t r, uint8_t g, uint8_t b) : r_(r), g_(g), b_(b) {}

RGBColor::~RGBColor() {}

string RGBColor::ansi_code_foreground() const {
    return "\e[38;2;" + ansi_code_base() + "m";
}

string RGBColor::ansi_code_background() const {
    return "\e[48;2;" + ansi_code_base() + "m";
}

string RGBColor::ansi_code_base() const {
    return to_string(r_) + ";" + to_string(g_) + ";" + to_string(b_);
}
