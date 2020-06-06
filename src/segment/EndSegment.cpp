#include "segment/EndSegment.h"

namespace velocity::segment {
    EndSegment::EndSegment() {}

    EndSegment::~EndSegment() {}

    void EndSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }
} // namespace velocity::segment
