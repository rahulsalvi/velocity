#include "style/ItalicStyle.h"

namespace velocity::style {
    ItalicStyle::ItalicStyle() {}

    ItalicStyle::~ItalicStyle() {}

    string ItalicStyle::accept_start(StyleVisitor& visitor) { return visitor.visit_start(*this); }

    string ItalicStyle::accept_end(StyleVisitor& visitor) { return visitor.visit_end(*this); }
} // namespace velocity::style
