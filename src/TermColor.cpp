#include "TermColor.h"

namespace velocity::color {
    TermColor::TermColor(string color_str) : color_str_(color_str) {}

    TermColor::~TermColor() {}

    string TermColor::accept_foreground(ColorVisitor& visitor) {
        return visitor.visit_foreground(*this);
    }

    string TermColor::accept_background(ColorVisitor& visitor) {
        return visitor.visit_background(*this);
    }

    string TermColor::color_str() { return color_str_; }
} // namespace velocity::color
