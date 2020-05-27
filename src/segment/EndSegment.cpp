#include "segment/EndSegment.h"
#include "color/ResetColor.h"

using std::make_shared;
using velocity::color::ResetColor;

namespace velocity::segment {
    EndSegment::EndSegment()
        : Segment(Format(make_shared<ResetColor>(), make_shared<ResetColor>(), {}), "", "", 0) {}

    EndSegment::~EndSegment() {}

    void EndSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }
} // namespace velocity::segment
