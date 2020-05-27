#include "style/ResetStyle.h"

namespace velocity::style {
    ResetStyle::ResetStyle() {}

    ResetStyle::~ResetStyle() {}

    string ResetStyle::accept_start(StyleVisitor& visitor) { return visitor.visit_start(*this); }

    string ResetStyle::accept_end(StyleVisitor& visitor) { return visitor.visit_end(*this); }
} // namespace velocity::style
