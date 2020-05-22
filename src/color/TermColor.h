#ifndef TERMCOLOR_H
#define TERMCOLOR_H

#include "color/Color.h"
#include "color/visitor/ColorVisitor.h"

namespace velocity::color {
    class TermColor : public Color {
        public:
        TermColor(string color_str = "black");
        virtual ~TermColor();
        virtual string accept_foreground(ColorVisitor& visitor);
        virtual string accept_background(ColorVisitor& visitor);

        string color_str();

        private:
        string color_str_;
    };
} // namespace velocity::color

#endif // TERMCOLOR_H
