#ifndef ENVIRONMENTCONDITIONALSEGMENT_H
#define ENVIRONMENTCONDITIONALSEGMENT_H

#include "segment/ConditionalSegment.h"
#include "segment/visitor/SegmentVisitor.h"

namespace velocity::segment {
    class EnvironmentConditionalSegment : public ConditionalSegment {
        public:
        EnvironmentConditionalSegment(string var, string target, Condition cond);
        virtual ~EnvironmentConditionalSegment();

        virtual void accept(SegmentVisitor& visitor) override;

        virtual bool eval() override;

        private:
        string    var_;
        string    target_;
        Condition cond_;
    };
} // namespace velocity::segment

#endif // ENVIRONMENTCONDITIONALSEGMENT_H
