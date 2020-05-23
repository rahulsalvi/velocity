#ifndef CWDSEGMENT_H
#define CWDSEGMENT_H

#include <vector>

#include "segment/Segment.h"
#include "segment/visitor/SegmentVisitor.h"

using std::vector;

namespace velocity::segment {
    class CWDSegment : public Segment {
        public:
        CWDSegment(Format format, string outer_separator, string inner_separator, int priority);
        virtual ~CWDSegment();

        virtual void accept(SegmentVisitor& visitor) override;

        const string&         inner_separator();
        const vector<string>& directories();

        virtual void eval();

        private:
        string         inner_separator_;
        vector<string> directories_;
    };
} // namespace velocity::segment

#endif // CWDSEGMENT_H
