#ifndef CONTROLSEGMENT_H
#define CONTROLSEGMENT_H

#include <memory>

#include "segment/Segment.h"

using std::make_shared;

namespace velocity::segment {
    class ControlSegment : public Segment {
        public:
        ~ControlSegment() {}

        virtual shared_ptr<Format> format() const override { return make_shared<Format>(); }
    };
} // namespace velocity::segment

#endif // CONTROLSEGMENT_H
