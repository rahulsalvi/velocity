#include "segment/StartSegment.h"

namespace velocity::segment {
    StartSegment::StartSegment() {}

    StartSegment::~StartSegment() {}

    void StartSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }
} // namespace velocity::segment
