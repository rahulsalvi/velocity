#ifndef STRIKETHROUGHSTYLE_H
#define STRIKETHROUGHSTYLE_H

#include "style/Style.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class StrikethroughStyle : public Style {
        public:
        StrikethroughStyle();
        virtual ~StrikethroughStyle();
        virtual string accept_start(StyleVisitor& visitor);
        virtual string accept_end(StyleVisitor& visitor);
    };
} // namespace velocity::style

#endif // STRIKETHROUGHSTYLE_H
