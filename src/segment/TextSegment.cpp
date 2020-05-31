#include "segment/TextSegment.h"

namespace velocity::segment {
    TextSegment::TextSegment(Format format, int priority, string text, string separator)
        : Segment(format, priority), text_(text), separator_(separator) {}

    TextSegment::~TextSegment() {}

    const string& TextSegment::text() const { return text_; }

    const string& TextSegment::separator() const { return separator_; }

    void TextSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }
} // namespace velocity::segment
