#include "segment/StartSegment.h"
#include "color/ResetColor.h"
#include "style/NormalStyle.h"

using std::make_shared;
using velocity::color::ResetColor;
using velocity::style::NormalStyle;

namespace velocity::segment {
    StartSegment::StartSegment()
        : Segment(Format(make_shared<ResetColor>(),
                         make_shared<ResetColor>(),
                         make_shared<NormalStyle>()),
                  "",
                  "",
                  0) {}

    StartSegment::~StartSegment() {}

    void StartSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }
} // namespace velocity::segment
