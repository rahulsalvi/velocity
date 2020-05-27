#ifndef BOLDSTYLE_H
#define BOLDSTYLE_H

#include "style/Style.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class BoldStyle : public Style {
        public:
        BoldStyle();
        virtual ~BoldStyle();
        virtual string accept_start(StyleVisitor& visitor);
        virtual string accept_end(StyleVisitor& visitor);
    };
} // namespace velocity::style

#endif // BOLDSTYLE_H
