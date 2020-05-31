#ifndef CWDSEGMENT_H
#define CWDSEGMENT_H

#include <vector>

#include "segment/Segment.h"
#include "segment/visitor/SegmentVisitor.h"

using std::vector;

namespace velocity::segment {
    class CWDSegment : public Segment {
        public:
        CWDSegment(Format format, int priority, string outer_separator, string inner_separator);
        virtual ~CWDSegment();

        virtual void accept(SegmentVisitor& visitor) override;

        const string&         outer_separator() const;
        const string&         inner_separator() const;
        const vector<string>& directories() const;

        virtual void eval();

        private:
        string         outer_separator_;
        string         inner_separator_;
        vector<string> directories_;
    };
} // namespace velocity::segment

#endif // CWDSEGMENT_H
