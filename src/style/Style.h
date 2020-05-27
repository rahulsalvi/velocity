#ifndef STYLE_H
#define STYLE_H

#include <string>

using std::string;

namespace velocity::style {
    class StyleVisitor;

    class Style {
        public:
        virtual ~Style() {}
        virtual string accept_start(StyleVisitor& visitor) = 0;
        virtual string accept_end(StyleVisitor& visitor)   = 0;
    };
} // namespace velocity::style

#endif // STYLE_H
