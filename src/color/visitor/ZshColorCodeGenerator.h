#ifndef ZSHCOLORCODEGENERATOR_H
#define ZSHCOLORCODEGENERATOR_H

#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "color/visitor/ANSIColorCodeGenerator.h"
#include "color/visitor/ColorVisitor.h"

namespace velocity::color {
    class ZshColorCodeGenerator : public ANSIColorCodeGenerator {
        public:
        ZshColorCodeGenerator();
        virtual ~ZshColorCodeGenerator();

        virtual string visit_foreground(TermColor& color);
        virtual string visit_background(TermColor& color);

        virtual string visit_foreground(RGBColor& color);
        virtual string visit_background(RGBColor& color);

        virtual string visit_foreground(ResetColor& color);
        virtual string visit_background(ResetColor& color);
    };
} // namespace velocity::color

#endif // ZSHCOLORCODEGENERATOR_H
