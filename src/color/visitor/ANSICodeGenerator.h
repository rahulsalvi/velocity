#ifndef ANSICODEGENERATORH
#define ANSICODEGENERATORH

#include <string>

#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "color/visitor/ColorVisitor.h"

namespace velocity::color {
    class ANSICodeGenerator : public ColorVisitor {
        public:
        ANSICodeGenerator();
        ~ANSICodeGenerator();

        virtual string visit_foreground(TermColor& color);
        virtual string visit_background(TermColor& color);

        virtual string visit_foreground(RGBColor& color);
        virtual string visit_background(RGBColor& color);

        virtual string visit_foreground(ResetColor& color);
        virtual string visit_background(ResetColor& color);

        private:
        string rgb_code_base(RGBColor& color);
    };
} // namespace velocity::color

#endif // ANSICODEGENERATORH