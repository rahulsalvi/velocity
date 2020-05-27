#ifndef STYLEVISITOR_H
#define STYLEVISITOR_H

#include <string>

using std::string;

namespace velocity::style {
    class NormalStyle;
    class BoldStyle;
    class FaintStyle;
    class ItalicStyle;
    class UnderlineStyle;
    class DoubleUnderlineStyle;
    class StrikethroughStyle;

    class StyleVisitor {
        public:
        ~StyleVisitor() {}

        virtual string visit_start(NormalStyle& style) = 0;
        virtual string visit_end(NormalStyle& style)   = 0;

        virtual string visit_start(BoldStyle& style) = 0;
        virtual string visit_end(BoldStyle& style)   = 0;

        virtual string visit_start(FaintStyle& style) = 0;
        virtual string visit_end(FaintStyle& style)   = 0;

        virtual string visit_start(ItalicStyle& style) = 0;
        virtual string visit_end(ItalicStyle& style)   = 0;

        virtual string visit_start(UnderlineStyle& style) = 0;
        virtual string visit_end(UnderlineStyle& style)   = 0;

        virtual string visit_start(DoubleUnderlineStyle& style) = 0;
        virtual string visit_end(DoubleUnderlineStyle& style)   = 0;

        virtual string visit_start(StrikethroughStyle& style) = 0;
        virtual string visit_end(StrikethroughStyle& style)   = 0;
    };
} // namespace velocity::style

#endif // STYLEVISITOR_H
