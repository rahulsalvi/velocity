#include "style/DoubleUnderlineStyle.h"

namespace velocity::style {
    DoubleUnderlineStyle::DoubleUnderlineStyle() {}

    DoubleUnderlineStyle::~DoubleUnderlineStyle() {}

    string DoubleUnderlineStyle::accept_start(StyleVisitor& visitor) {
        return visitor.visit_start(*this);
    }

    string DoubleUnderlineStyle::accept_end(StyleVisitor& visitor) {
        return visitor.visit_end(*this);
    }
} // namespace velocity::style
