#include "StartSegment.h"
#include "ResetColor.h"

using std::make_shared;
using velocity::color::ResetColor;

namespace velocity::segment {
    StartSegment::StartSegment()
        : Segment(Format(make_shared<ResetColor>(), make_shared<ResetColor>()),
                  "",
                  "",
                  0,
                  false,
                  false,
                  false) {}

    StartSegment::~StartSegment() {}

    int StartSegment::length() { return 0; }

    int StartSegment::trim() { return 0; }

    void StartSegment::expand() {}

    void StartSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }
} // namespace velocity::segment
