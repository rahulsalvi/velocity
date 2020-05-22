#include "RGBColor.h"

namespace velocity::color {
    RGBColor::RGBColor(uint8_t r, uint8_t g, uint8_t b) : r_(r), g_(g), b_(b) {}

    RGBColor::~RGBColor() {}

    string RGBColor::accept_foreground(ColorVisitor& visitor) {
        return visitor.visit_foreground(*this);
    }

    string RGBColor::accept_background(ColorVisitor& visitor) {
        return visitor.visit_background(*this);
    }

    uint8_t RGBColor::r() { return r_; }

    uint8_t RGBColor::g() { return g_; }

    uint8_t RGBColor::b() { return b_; }
} // namespace velocity::color
