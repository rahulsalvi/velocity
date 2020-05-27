#include "color/TermColor256.h"

namespace velocity::color {
    TermColor256::TermColor256(uint8_t color) : color_(color) {}

    TermColor256::~TermColor256() {}

    string TermColor256::accept_foreground(ColorVisitor& visitor) {
        return visitor.visit_foreground(*this);
    }

    string TermColor256::accept_background(ColorVisitor& visitor) {
        return visitor.visit_background(*this);
    }

    uint8_t TermColor256::color() { return color_; }
} // namespace velocity::color
