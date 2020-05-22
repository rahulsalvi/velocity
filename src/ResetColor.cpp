#include "ResetColor.h"

namespace velocity::color {
    ResetColor::ResetColor() {}

    ResetColor::~ResetColor() {}

    string ResetColor::accept_foreground(ColorVisitor& visitor) {
        return visitor.visit_foreground(*this);
    }

    string ResetColor::accept_background(ColorVisitor& visitor) {
        return visitor.visit_background(*this);
    }
} // namespace velocity::color
