#ifndef TEXTSEGMENT_H
#define TEXTSEGMENT_H

#include <string>

#include "segment/DisplayedSegment.h"
#include "segment/visitor/SegmentVisitor.h"

using std::string;

namespace velocity::segment {
    class TextSegment : public DisplayedSegment {
        public:
        TextSegment(shared_ptr<Format> format, int priority, string text, string separator);
        virtual ~TextSegment();

        virtual const string& text() const;
        virtual const string& separator() const;

        virtual void accept(SegmentVisitor& visitor) override;

        private:
        string text_;
        string separator_;
    };
} // namespace velocity::segment

#endif // TEXTSEGMENT_H
