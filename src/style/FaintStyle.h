#ifndef FAINTSTYLE_H
#define FAINTSTYLE_H

#include "style/Style.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class FaintStyle : public Style {
        public:
        FaintStyle();
        virtual ~FaintStyle();
        virtual string accept_start(StyleVisitor& visitor);
        virtual string accept_end(StyleVisitor& visitor);
    };
} // namespace velocity::style

#endif // FAINTSTYLE_H
