#ifndef SEGMENT_H
#define SEGMENT_H

#include <memory>

#include "Format.h"

using std::shared_ptr;
using velocity::Format;

namespace velocity::segment {
    class SegmentVisitor;

    class Segment {
        public:
        virtual ~Segment() {}

        virtual shared_ptr<Format> format() const = 0;

        void set_next(shared_ptr<Segment> next) { next_ = next; }
        void set_prev(shared_ptr<Segment> prev) { prev_ = prev; }

        shared_ptr<Segment> next() { return next_; }
        shared_ptr<Segment> prev() { return prev_; }

        virtual void accept(SegmentVisitor& visitor) = 0;

        private:
        shared_ptr<Segment> prev_;
        shared_ptr<Segment> next_;
    };
} // namespace velocity::segment

#endif // SEGMENT_H
