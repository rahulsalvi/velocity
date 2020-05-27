#ifndef ITALICSTYLE_H
#define ITALICSTYLE_H

#include "style/Style.h"
#include "style/visitor/StyleVisitor.h"

namespace velocity::style {
    class ItalicStyle : public Style {
        public:
        ItalicStyle();
        virtual ~ItalicStyle();
        virtual string accept_start(StyleVisitor& visitor);
        virtual string accept_end(StyleVisitor& visitor);
    };
} // namespace velocity::style

#endif // ITALICSTYLE_H
