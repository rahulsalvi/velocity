#include "style/visitor/ZshStyleCodeGenerator.h"

namespace velocity::style {
    ZshStyleCodeGenerator::ZshStyleCodeGenerator() {}

    ZshStyleCodeGenerator::~ZshStyleCodeGenerator() {}

    string ZshStyleCodeGenerator::visit_start(BoldStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_start(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_end(BoldStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_end(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_start(FaintStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_start(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_end(FaintStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_end(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_start(ItalicStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_start(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_end(ItalicStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_end(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_start(UnderlineStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_start(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_end(UnderlineStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_end(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_start(DoubleUnderlineStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_start(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_end(DoubleUnderlineStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_end(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_start(StrikethroughStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_start(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_end(StrikethroughStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_end(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_start(ResetStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_start(style) + "%}";
    }

    string ZshStyleCodeGenerator::visit_end(ResetStyle& style) {
        return "%{" + ANSIStyleCodeGenerator::visit_end(style) + "%}";
    }
} // namespace velocity::style
