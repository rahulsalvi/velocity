#ifndef ENDSEGMENT_H
#define ENDSEGMENT_H

#include "Segment.h"
#include "SegmentVisitor.h"

namespace velocity::segment {
    class EndSegment : public Segment {
        public:
        EndSegment();
        virtual ~EndSegment();

        virtual int  length() override;
        virtual int  trim() override;
        virtual void expand() override;

        virtual void accept(SegmentVisitor& visitor) override;
    };
} // namespace velocity::segment

#endif // ENDSEGMENT_H
