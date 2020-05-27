#ifndef TERMCOLOR256_H
#define TERMCOLOR256_H

#include <cstdint>

#include "color/Color.h"
#include "color/visitor/ColorVisitor.h"

namespace velocity::color {
    class TermColor256 : public Color {
        public:
        TermColor256(uint8_t color);
        virtual ~TermColor256();
        virtual string accept_foreground(ColorVisitor& visitor);
        virtual string accept_background(ColorVisitor& visitor);

        uint8_t color();

        private:
        uint8_t color_;
    };
} // namespace velocity::color

#endif // TERMCOLOR256_H
