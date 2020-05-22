#ifndef TEXTSEGMENT_H
#define TEXTSEGMENT_H

#include "segment/Segment.h"
#include "segment/visitor/SegmentVisitor.h"

namespace velocity::segment {
    class TextSegment : public Segment {
        public:
        TextSegment(Format format, string text, string separator, int priority);
        virtual ~TextSegment();

        virtual int  length() override;
        virtual int  trim() override;
        virtual void expand() override;

        virtual void accept(SegmentVisitor& visitor) override;
    };
} // namespace velocity::segment

#endif // TEXTSEGMENT_H
