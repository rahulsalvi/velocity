#include "segment/TextSegment.h"
#include "utils.h"

namespace velocity::segment {
    TextSegment::TextSegment(Format format, string text, string separator, int priority)
        : Segment(format, " " + text + " ", separator, priority, false, false, true) {}

    TextSegment::~TextSegment() {}

    int TextSegment::length() { return utf8_strlen(text_) + utf8_strlen(separator_); }

    int TextSegment::trim() { return 0; }

    void TextSegment::expand() {}

    void TextSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }
} // namespace velocity::segment
