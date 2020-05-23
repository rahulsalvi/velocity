#include "zsh/ColorCodeGenerator.h"

namespace velocity::zsh {
    ColorCodeGenerator::ColorCodeGenerator() {}

    ColorCodeGenerator::~ColorCodeGenerator() {}

    string ColorCodeGenerator::visit_foreground(TermColor& color) {
        return "%{" + ANSICodeGenerator::visit_foreground(color) + "%}";
    }

    string ColorCodeGenerator::visit_background(TermColor& color) {
        return "%{" + ANSICodeGenerator::visit_background(color) + "%}";
    }

    string ColorCodeGenerator::visit_foreground(RGBColor& color) {
        return "%{" + ANSICodeGenerator::visit_foreground(color) + "%}";
    }

    string ColorCodeGenerator::visit_background(RGBColor& color) {
        return "%{" + ANSICodeGenerator::visit_background(color) + "%}";
    }

    string ColorCodeGenerator::visit_foreground(ResetColor& color) {
        return "%{" + ANSICodeGenerator::visit_foreground(color) + "%}";
    }

    string ColorCodeGenerator::visit_background(ResetColor& color) {
        return "%{" + ANSICodeGenerator::visit_background(color) + "%}";
    }
} // namespace velocity::zsh
