#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <cstdint>

#include "color/Color.h"
#include "color/visitor/ColorVisitor.h"

namespace velocity::color {
    class RGBColor : public Color {
        public:
        RGBColor(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0);
        virtual ~RGBColor();
        virtual string accept_foreground(ColorVisitor& visitor);
        virtual string accept_background(ColorVisitor& visitor);

        uint8_t r();
        uint8_t g();
        uint8_t b();

        private:
        uint8_t r_;
        uint8_t g_;
        uint8_t b_;
    };
} // namespace velocity::color

#endif // RGBCOLOR_H
