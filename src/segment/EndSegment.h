#ifndef ENDSEGMENT_H
#define ENDSEGMENT_H

#include "segment/ControlSegment.h"
#include "segment/visitor/SegmentVisitor.h"

namespace velocity::segment {
    class EndSegment : public ControlSegment {
        public:
        EndSegment();
        virtual ~EndSegment();

        virtual void accept(SegmentVisitor& visitor) override;
    };
} // namespace velocity::segment

#endif // ENDSEGMENT_H
