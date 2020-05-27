#include "style/StrikethroughStyle.h"

namespace velocity::style {
    StrikethroughStyle::StrikethroughStyle() {}

    StrikethroughStyle::~StrikethroughStyle() {}

    string StrikethroughStyle::accept_start(StyleVisitor& visitor) {
        return visitor.visit_start(*this);
    }

    string StrikethroughStyle::accept_end(StyleVisitor& visitor) {
        return visitor.visit_end(*this);
    }
} // namespace velocity::style
