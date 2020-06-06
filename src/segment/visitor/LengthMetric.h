#ifndef LENGTHMETRIC_H
#define LENGTHMETRIC_H

#include "segment/Segment.h"
#include "segment/visitor/SegmentVisitor.h"

namespace velocity::segment {
    class LengthMetric : public SegmentVisitor {
        public:
        ~LengthMetric() {}
        virtual int  length() const = 0;
        virtual void reset()        = 0;
    };
} // namespace velocity::segment

#endif // LENGTHMETRIC_H
