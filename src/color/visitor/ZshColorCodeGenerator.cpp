#include "color/visitor/ZshColorCodeGenerator.h"

namespace velocity::color {
    ZshColorCodeGenerator::ZshColorCodeGenerator() {}

    ZshColorCodeGenerator::~ZshColorCodeGenerator() {}

    string ZshColorCodeGenerator::visit_foreground(TermColor& color) {
        return "%{" + ANSIColorCodeGenerator::visit_foreground(color) + "%}";
    }

    string ZshColorCodeGenerator::visit_background(TermColor& color) {
        return "%{" + ANSIColorCodeGenerator::visit_background(color) + "%}";
    }

    string ZshColorCodeGenerator::visit_foreground(TermColor256& color) {
        return "%{" + ANSIColorCodeGenerator::visit_foreground(color) + "%}";
    }

    string ZshColorCodeGenerator::visit_background(TermColor256& color) {
        return "%{" + ANSIColorCodeGenerator::visit_background(color) + "%}";
    }

    string ZshColorCodeGenerator::visit_foreground(RGBColor& color) {
        return "%{" + ANSIColorCodeGenerator::visit_foreground(color) + "%}";
    }

    string ZshColorCodeGenerator::visit_background(RGBColor& color) {
        return "%{" + ANSIColorCodeGenerator::visit_background(color) + "%}";
    }

    string ZshColorCodeGenerator::visit_foreground(ResetColor& color) {
        return "%{" + ANSIColorCodeGenerator::visit_foreground(color) + "%}";
    }

    string ZshColorCodeGenerator::visit_background(ResetColor& color) {
        return "%{" + ANSIColorCodeGenerator::visit_background(color) + "%}";
    }
} // namespace velocity::color
