#ifndef DISPLAYEDSEGMENT_H
#define DISPLAYEDSEGMENT_H

#include "Format.h"
#include "segment/Segment.h"

using velocity::Format;

namespace velocity::segment {
    class DisplayedSegment : public Segment {
        public:
        DisplayedSegment(shared_ptr<Format> format, int priority)
            : format_(format), priority_(priority) {}
        ~DisplayedSegment() {}

        virtual shared_ptr<Format> format() const override { return format_; }
        virtual int                priority() const { return priority_; }

        protected:
        shared_ptr<Format> format_;
        int                priority_;
    };
} // namespace velocity::segment

#endif // DISPLAYEDSEGMENT_H
