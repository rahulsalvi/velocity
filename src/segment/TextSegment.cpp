#include "segment/TextSegment.h"
#include "utils.h"

namespace velocity::segment {
    TextSegment::TextSegment(Format format, string text, string separator, int priority)
        : Segment(format, " " + text + " ", separator, priority) {}

    TextSegment::~TextSegment() {}

    void TextSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }
} // namespace velocity::segment
