#ifndef GITREPOCONDITIONALSEGMENT_H
#define GITREPOCONDITIONALSEGMENT_H

#include "segment/ConditionalSegment.h"
#include "segment/visitor/SegmentVisitor.h"

namespace velocity::segment {
    class GitRepoConditionalSegment : public ConditionalSegment {
        public:
        GitRepoConditionalSegment();
        virtual ~GitRepoConditionalSegment();

        virtual void accept(SegmentVisitor& visitor) override;

        virtual bool eval() override;
    };
} // namespace velocity::segment

#endif // GITREPOCONDITIONALSEGMENT_H
