#ifndef STARTSEGMENT_H
#define STARTSEGMENT_H

#include "Segment.h"
#include "SegmentVisitor.h"

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
