#ifndef RESETSTYLE_H
#define RESETSTYLE_H

#include "style/Style.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class ResetStyle : public Style {
        public:
        ResetStyle();
        virtual ~ResetStyle();
        virtual string accept_start(StyleVisitor& visitor);
        virtual string accept_end(StyleVisitor& visitor);
    };
} // namespace velocity::style

#endif // RESETSTYLE_H
