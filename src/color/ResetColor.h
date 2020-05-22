#ifndef RESETCOLOR_H
#define RESETCOLOR_H

#include "color/Color.h"
#include "color/visitor/ColorVisitor.h"

namespace velocity::color {
    class ResetColor : public Color {
        public:
        ResetColor();
        virtual ~ResetColor();
        virtual string accept_foreground(ColorVisitor& visitor);
        virtual string accept_background(ColorVisitor& visitor);
    };
} // namespace velocity::color

#endif // RESETCOLOR_H
