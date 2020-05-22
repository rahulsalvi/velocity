#ifndef FORMAT_H
#define FORMAT_H

#include <memory>

#include "Color.h"

using std::shared_ptr;

namespace velocity::color {
    class Format {
        public:
        Format(shared_ptr<Color> foreground, shared_ptr<Color> background);
        ~Format();

        void set_foreground(shared_ptr<Color> foreground);
        void set_background(shared_ptr<Color> background);

        shared_ptr<Color> foreground() const;
        shared_ptr<Color> background() const;

        private:
        shared_ptr<Color> foreground_;
        shared_ptr<Color> background_;
    };
} // namespace velocity::color

#endif // FORMAT_H
