#ifndef ZSHCOLORCODEGENERATOR_H
#define ZSHCOLORCODEGENERATOR_H

#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "color/TermColor256.h"
#include "color/visitor/ANSIColorCodeGenerator.h"
#include "color/visitor/ColorVisitor.h"

namespace velocity::color {
    class ZshColorCodeGenerator : public ANSIColorCodeGenerator {
        public:
        ZshColorCodeGenerator();
        virtual ~ZshColorCodeGenerator();

        virtual string visit_foreground(TermColor& color) override;
        virtual string visit_background(TermColor& color) override;

        virtual string visit_foreground(TermColor256& color) override;
        virtual string visit_background(TermColor256& color) override;

        virtual string visit_foreground(RGBColor& color) override;
        virtual string visit_background(RGBColor& color) override;

        virtual string visit_foreground(ResetColor& color) override;
        virtual string visit_background(ResetColor& color) override;
    };
} // namespace velocity::color

#endif // ZSHCOLORCODEGENERATOR_H
