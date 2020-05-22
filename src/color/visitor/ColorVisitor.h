#ifndef COLORVISITOR_H
#define COLORVISITOR_H

#include <string>

using std::string;

namespace velocity::color {
    class TermColor;
    class RGBColor;
    class ResetColor;

    class ColorVisitor {
        public:
        ~ColorVisitor(){};

        virtual string visit_foreground(TermColor& color) = 0;
        virtual string visit_background(TermColor& color) = 0;

        virtual string visit_foreground(RGBColor& color) = 0;
        virtual string visit_background(RGBColor& color) = 0;

        virtual string visit_foreground(ResetColor& color) = 0;
        virtual string visit_background(ResetColor& color) = 0;
    };
} // namespace velocity::color

#endif // COLORVISITOR_H
