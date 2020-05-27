#ifndef COLOR_H
#define COLOR_H

#include <string>

using std::string;

namespace velocity::color {
    class ColorVisitor;

    class Color {
        public:
        virtual ~Color() {}
        virtual string accept_foreground(ColorVisitor& visitor) = 0;
        virtual string accept_background(ColorVisitor& visitor) = 0;
    };
} // namespace velocity::color

#endif // COLOR_H
