#ifndef ZSHCOLORCODEGENERATOR_H
#define ZSHCOLORCODEGENERATOR_H

#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "color/visitor/ANSICodeGenerator.h"
#include "color/visitor/ColorVisitor.h"

using velocity::color::ANSICodeGenerator;
using velocity::color::ResetColor;
using velocity::color::RGBColor;
using velocity::color::TermColor;

namespace velocity::zsh {
    class ColorCodeGenerator : public ANSICodeGenerator {
        public:
        ColorCodeGenerator();
        virtual ~ColorCodeGenerator();

        virtual string visit_foreground(TermColor& color);
        virtual string visit_background(TermColor& color);

        virtual string visit_foreground(RGBColor& color);
        virtual string visit_background(RGBColor& color);

        virtual string visit_foreground(ResetColor& color);
        virtual string visit_background(ResetColor& color);
    };
} // namespace velocity::zsh

#endif // ZSHCOLORCODEGENERATOR_H
