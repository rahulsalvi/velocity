#include "style/BoldStyle.h"

namespace velocity::style {
    BoldStyle::BoldStyle() {}

    BoldStyle::~BoldStyle() {}

    string BoldStyle::accept_start(StyleVisitor& visitor) { return visitor.visit_start(*this); }

    string BoldStyle::accept_end(StyleVisitor& visitor) { return visitor.visit_end(*this); }
} // namespace velocity::style
