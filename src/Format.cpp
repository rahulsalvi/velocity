#include "Format.h"

namespace velocity {
    Format::Format(shared_ptr<Color> foreground,
                   shared_ptr<Color> background,
                   shared_ptr<Style> style)
        : foreground_(foreground), background_(background), style_(style) {}

    Format::~Format() {}

    void Format::set_foreground(shared_ptr<Color> foreground) { foreground_ = foreground; }

    void Format::set_background(shared_ptr<Color> background) { background_ = background; }

    void Format::set_style(shared_ptr<Style> style) { style_ = style; }

    shared_ptr<Color> Format::foreground() const { return foreground_; }

    shared_ptr<Color> Format::background() const { return background_; }

    shared_ptr<Style> Format::style() const { return style_; }
} // namespace velocity
