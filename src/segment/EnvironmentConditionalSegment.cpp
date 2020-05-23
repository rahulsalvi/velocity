#include <cstdio>
#include <cstdlib>

#include "segment/EnvironmentConditionalSegment.h"

using std::getenv;

namespace velocity::segment {
    EnvironmentConditionalSegment::EnvironmentConditionalSegment(string    var,
                                                                 string    target,
                                                                 Condition cond)
        : var_(var), target_(target), cond_(cond) {}

    EnvironmentConditionalSegment::~EnvironmentConditionalSegment() {}

    void EnvironmentConditionalSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }

    bool EnvironmentConditionalSegment::eval() {
        char*  res = getenv(var_.c_str());
        string val;
        if (!res) {
            val = "";
        } else {
            val.assign(res);
        }
        int cmp = val.compare(target_);
        switch (cond_) {
            case EQUALS:
                return (cmp == 0);
            case NOT_EQUALS:
                return (cmp != 0);
            case GREATER_THAN:
                return (cmp > 0);
            case LESS_THAN:
                return (cmp < 0);
            case GREATER_THAN_EQUALS:
                return (cmp >= 0);
            case LESS_THAN_EQUALS:
                return (cmp <= 0);
            default:
                return false;
                break;
        }
    }
} // namespace velocity::segment
