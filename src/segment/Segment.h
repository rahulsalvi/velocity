#ifndef SEGMENT_H
#define SEGMENT_H

#include <memory>
#include <string>

#include "color/Format.h"

using std::shared_ptr;
using std::string;
using velocity::color::Format;

namespace velocity::segment {
    class SegmentVisitor;

    class Segment {
        public:
        Segment(Format format, string text, string separator, int priority)
            : format_(format), text_(text), separator_(separator), priority_(priority) {}
        virtual ~Segment(){};

        const Format& format() { return format_; };
        const string& text() { return text_; };
        const string& separator() { return separator_; };
        int           priority() const { return priority_; }

        void set_next(shared_ptr<Segment> next) { next_ = next; }
        void set_prev(shared_ptr<Segment> prev) { prev_ = prev; }

        shared_ptr<Segment> next() { return next_; }
        shared_ptr<Segment> prev() { return prev_; }

        virtual void accept(SegmentVisitor& visitor) = 0;

        protected:
        shared_ptr<Segment> prev_;
        shared_ptr<Segment> next_;

        Format format_;
        string text_;
        string separator_;
        int    priority_;
    };
} // namespace velocity::segment

#endif // SEGMENT_H
