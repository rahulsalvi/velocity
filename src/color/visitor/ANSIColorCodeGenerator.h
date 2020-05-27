#ifndef ANSICOLORCODEGENERATOR_H
#define ANSICOLORCODEGENERATOR_H

#include <string>

#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "color/visitor/ColorVisitor.h"

namespace velocity::color {
    class ANSIColorCodeGenerator : public ColorVisitor {
        public:
        ANSIColorCodeGenerator();
        virtual ~ANSIColorCodeGenerator();

        virtual string visit_foreground(TermColor& color) override;
        virtual string visit_background(TermColor& color) override;

        virtual string visit_foreground(RGBColor& color) override;
        virtual string visit_background(RGBColor& color) override;

        virtual string visit_foreground(ResetColor& color) override;
        virtual string visit_background(ResetColor& color) override;

        private:
        string rgb_code_base(RGBColor& color);
    };
} // namespace velocity::color

#endif // ANSICOLORCODEGENERATOR_H
