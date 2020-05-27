#ifndef UNDERLINESTYLE_H
#define UNDERLINESTYLE_H

#include "style/Style.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class UnderlineStyle : public Style {
        public:
        UnderlineStyle();
        virtual ~UnderlineStyle();
        virtual string accept_start(StyleVisitor& visitor);
        virtual string accept_end(StyleVisitor& visitor);
    };
} // namespace velocity::style

#endif // UNDERLINESTYLE_H
