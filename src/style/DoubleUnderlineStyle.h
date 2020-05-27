#ifndef DOUBLEUNDERLINESTYLE_H
#define DOUBLEUNDERLINESTYLE_H

#include "style/Style.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class DoubleUnderlineStyle : public Style {
        public:
        DoubleUnderlineStyle();
        virtual ~DoubleUnderlineStyle();
        virtual string accept_start(StyleVisitor& visitor);
        virtual string accept_end(StyleVisitor& visitor);
    };
} // namespace velocity::style

#endif // DOUBLEUNDERLINESTYLE_H
