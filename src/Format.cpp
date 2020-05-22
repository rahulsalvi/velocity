#include "Format.h"

Format::Format(shared_ptr<Color> foreground, shared_ptr<Color> background)
    : foreground_(foreground), background_(background) {}

Format::~Format() {}

void Format::set_foreground(shared_ptr<Color> foreground) {
    foreground_ = foreground;
}

void Format::set_background(shared_ptr<Color> background) {
    background_ = background;
}

shared_ptr<Color> Format::foreground() const {
    return foreground_;
}

shared_ptr<Color> Format::background() const {
    return background_;
}
