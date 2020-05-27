#ifndef NORMALSTYLE_H
#define NORMALSTYLE_H

#include "style/Style.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class NormalStyle : public Style {
        public:
        NormalStyle();
        virtual ~NormalStyle();
        virtual string accept_start(StyleVisitor& visitor);
        virtual string accept_end(StyleVisitor& visitor);
    };
} // namespace velocity::style

#endif // NORMALSTYLE_H
