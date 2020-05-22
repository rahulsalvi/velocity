#ifndef STARTSEGMENT_H
#define STARTSEGMENT_H

#include "segment/Segment.h"
#include "segment/visitor/SegmentVisitor.h"

namespace velocity::segment {
    class StartSegment : public Segment {
        public:
        StartSegment();
        virtual ~StartSegment();

        virtual int  length() override;
        virtual int  trim() override;
        virtual void expand() override;

        virtual void accept(SegmentVisitor& visitor) override;
    };
} // namespace velocity::segment

#endif // STARTSEGMENT_H