#ifndef CONDITIONALSEGMENT_H
#define CONDITIONALSEGMENT_H

#include <memory>

#include "segment/ControlSegment.h"
#include "segment/visitor/SegmentVisitor.h"

namespace velocity::segment {
    enum Condition {
        EQUALS,
        NOT_EQUALS,
        GREATER_THAN,
        LESS_THAN,
        GREATER_THAN_EQUALS,
        LESS_THAN_EQUALS
    };
    class ConditionalSegment : public ControlSegment {
        public:
        ConditionalSegment() {}
        virtual ~ConditionalSegment() {}

        virtual void accept(SegmentVisitor& visitor) = 0;

        void set_true_segment(shared_ptr<Segment> true_segment) { true_segment_ = true_segment; }
        void set_false_segment(shared_ptr<Segment> false_segment) {
            false_segment_ = false_segment;
        }

        shared_ptr<Segment> true_segment() { return true_segment_; }
        shared_ptr<Segment> false_segment() { return false_segment_; }

        virtual bool eval() = 0;

        private:
        shared_ptr<Segment> true_segment_;
        shared_ptr<Segment> false_segment_;
    };
} // namespace velocity::segment

#endif // CONDITIONALSEGMENT_H
