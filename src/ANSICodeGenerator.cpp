#include <unordered_map>

#include "ANSICodeGenerator.h"

using std::to_string;
using std::unordered_map;

static unordered_map<string, string> color2fgcode = {{"black", "30"},
                                                     {"red", "31"},
                                                     {"green", "32"},
                                                     {"yellow", "33"},
                                                     {"blue", "34"},
                                                     {"magenta", "35"},
                                                     {"cyan", "36"},
                                                     {"white", "37"},
                                                     {"brblack", "90"},
                                                     {"brred", "91"},
                                                     {"brgreen", "92"},
                                                     {"bryellow", "93"},
                                                     {"brblue", "94"},
                                                     {"brmagenta", "95"},
                                                     {"brcyan", "96"},
                                                     {"brwhite", "97"}};
static unordered_map<string, string> color2bgcode = {{"black", "40"},
                                                     {"red", "41"},
                                                     {"green", "42"},
                                                     {"yellow", "43"},
                                                     {"blue", "44"},
                                                     {"magenta", "45"},
                                                     {"cyan", "46"},
                                                     {"white", "47"},
                                                     {"brblack", "100"},
                                                     {"brred", "101"},
                                                     {"brgreen", "102"},
                                                     {"bryellow", "103"},
                                                     {"brblue", "104"},
                                                     {"brmagenta", "105"},
                                                     {"brcyan", "106"},
                                                     {"brwhite", "107"}};

namespace velocity::color {
    ANSICodeGenerator::ANSICodeGenerator() {}

    ANSICodeGenerator::~ANSICodeGenerator() {}

    string ANSICodeGenerator::visit_foreground(TermColor& color) {
        return "\e[" + color2fgcode[color.color_str()] + "m";
    }

    string ANSICodeGenerator::visit_background(TermColor& color) {
        return "\e[" + color2bgcode[color.color_str()] + "m";
    }

    string ANSICodeGenerator::visit_foreground(RGBColor& color) {
        return "\e[38;2;" + rgb_code_base(color) + "m";
    }

    string ANSICodeGenerator::visit_background(RGBColor& color) {
        return "\e[48;2;" + rgb_code_base(color) + "m";
    }

    string ANSICodeGenerator::visit_foreground(ResetColor&) { return "\e[39m"; }

    string ANSICodeGenerator::visit_background(ResetColor&) { return "\e[49m"; }

    string ANSICodeGenerator::rgb_code_base(RGBColor& color) {
        return to_string(color.r()) + ";" + to_string(color.g()) + ";" + to_string(color.b());
    }
} // namespace velocity::color
