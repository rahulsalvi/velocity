#include "style/UnderlineStyle.h"

namespace velocity::style {
    UnderlineStyle::UnderlineStyle() {}

    UnderlineStyle::~UnderlineStyle() {}

    string UnderlineStyle::accept_start(StyleVisitor& visitor) {
        return visitor.visit_start(*this);
    }

    string UnderlineStyle::accept_end(StyleVisitor& visitor) { return visitor.visit_end(*this); }
} // namespace velocity::style
