#include <iostream>

#include "RGBColor.h"
#include "ResetColor.h"
#include "TermColor.h"

int main() {
    auto rgb   = RGBColor(255, 0, 0);
    auto term  = TermColor("cyan");
    auto reset = ResetColor();
    std::cout << rgb.ansi_code_background() << term.ansi_code_foreground() << "hello, world"
              << reset.ansi_code_foreground() << reset.ansi_code_background() << std::endl;
    return 0;
}
