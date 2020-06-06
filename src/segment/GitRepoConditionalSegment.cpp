#include "segment/GitRepoConditionalSegment.h"
#include "utils.h"

using velocity::utils::get_cwd;
using velocity::utils::path_exists;

namespace velocity::segment {
    GitRepoConditionalSegment::GitRepoConditionalSegment() {}

    GitRepoConditionalSegment::~GitRepoConditionalSegment() {}

    void GitRepoConditionalSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }

    bool GitRepoConditionalSegment::eval() {
        string cwd = get_cwd();
        if (cwd.empty()) { return false; }

        while (!cwd.empty()) {
            string temp = cwd + "/.git";
            if (path_exists(temp)) { return true; }
            size_t pos = cwd.find_last_of("/");
            cwd        = cwd.substr(0, pos);
        }
        return false;
    }
} // namespace velocity::segment
