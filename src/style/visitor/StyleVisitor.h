#ifndef STYLEVISITOR_H
#define STYLEVISITOR_H

#include <string>

using std::string;

namespace velocity::style {
    class BoldStyle;
    class NormalStyle;

    class StyleVisitor {
        public:
        ~StyleVisitor() {}

        virtual string visit_start(BoldStyle& style) = 0;
        virtual string visit_end(BoldStyle& style)   = 0;

        virtual string visit_start(NormalStyle& style) = 0;
        virtual string visit_end(NormalStyle& style)   = 0;
    };
} // namespace velocity::style

#endif // STYLEVISITOR_H
