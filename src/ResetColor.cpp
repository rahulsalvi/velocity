#include "ResetColor.h"

ResetColor::ResetColor() {}

ResetColor::~ResetColor() {}

string ResetColor::ansi_code_foreground() const {
    return "\e[39m";
}

string ResetColor::ansi_code_background() const {
    return "\e[49m";
}
