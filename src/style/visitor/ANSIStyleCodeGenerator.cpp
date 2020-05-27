#include "style/visitor/ANSIStyleCodeGenerator.h"

namespace velocity::style {
    ANSIStyleCodeGenerator::ANSIStyleCodeGenerator() {}

    ANSIStyleCodeGenerator::~ANSIStyleCodeGenerator() {}

    string ANSIStyleCodeGenerator::visit_start(BoldStyle&) { return "\e[1m"; }

    string ANSIStyleCodeGenerator::visit_end(BoldStyle&) { return "\e[22m"; }

    string ANSIStyleCodeGenerator::visit_start(FaintStyle&) { return "\e[2m"; }

    string ANSIStyleCodeGenerator::visit_end(FaintStyle&) { return "\e[22m"; }

    string ANSIStyleCodeGenerator::visit_start(ItalicStyle&) { return "\e[3m"; }

    string ANSIStyleCodeGenerator::visit_end(ItalicStyle&) { return "\e[23m"; }

    string ANSIStyleCodeGenerator::visit_start(UnderlineStyle&) { return "\e[4m"; }

    string ANSIStyleCodeGenerator::visit_end(UnderlineStyle&) { return "\e[24m"; }

    string ANSIStyleCodeGenerator::visit_start(DoubleUnderlineStyle&) { return "\e[21m"; }

    string ANSIStyleCodeGenerator::visit_end(DoubleUnderlineStyle&) { return "\e[24m"; }

    string ANSIStyleCodeGenerator::visit_start(StrikethroughStyle&) { return "\e[9m"; }

    string ANSIStyleCodeGenerator::visit_end(StrikethroughStyle&) { return "\e[29m"; }

    string ANSIStyleCodeGenerator::visit_start(ResetStyle&) { return "\e[22;23;24;29m"; }

    string ANSIStyleCodeGenerator::visit_end(ResetStyle&) { return "\e[22;23;24;29m"; }
} // namespace velocity::style
