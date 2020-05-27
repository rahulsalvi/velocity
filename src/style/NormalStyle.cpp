#include "style/NormalStyle.h"

namespace velocity::style {
    NormalStyle::NormalStyle() {}

    NormalStyle::~NormalStyle() {}

    string NormalStyle::accept_start(StyleVisitor& visitor) { return visitor.visit_start(*this); }

    string NormalStyle::accept_end(StyleVisitor& visitor) { return visitor.visit_end(*this); }
} // namespace velocity::style
