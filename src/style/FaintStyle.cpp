#include "style/FaintStyle.h"

namespace velocity::style {
    FaintStyle::FaintStyle() {}

    FaintStyle::~FaintStyle() {}

    string FaintStyle::accept_start(StyleVisitor& visitor) { return visitor.visit_start(*this); }

    string FaintStyle::accept_end(StyleVisitor& visitor) { return visitor.visit_end(*this); }
} // namespace velocity::style
