#ifndef FORMAT_H
#define FORMAT_H

#include <memory>

#include "color/Color.h"
#include "style/Style.h"

using std::shared_ptr;
using velocity::color::Color;
using velocity::style::Style;

namespace velocity {
    class Format {
        public:
        Format(shared_ptr<Color> foreground, shared_ptr<Color> background, shared_ptr<Style> style);
        ~Format();

        void set_foreground(shared_ptr<Color> foreground);
        void set_background(shared_ptr<Color> background);
        void set_style(shared_ptr<Style> style);

        shared_ptr<Color> foreground() const;
        shared_ptr<Color> background() const;
        shared_ptr<Style> style() const;

        private:
        shared_ptr<Color> foreground_;
        shared_ptr<Color> background_;
        shared_ptr<Style> style_;
    };
} // namespace velocity

#endif // FORMAT_H
