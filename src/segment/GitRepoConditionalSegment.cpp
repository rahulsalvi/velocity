#include <sys/stat.h>
#include <unistd.h>

#include "segment/GitRepoConditionalSegment.h"

#ifndef CWD_BUF_SIZE
#define CWD_BUF_SIZE 1024
#endif

namespace velocity::segment {
    GitRepoConditionalSegment::GitRepoConditionalSegment() {}

    GitRepoConditionalSegment::~GitRepoConditionalSegment() {}

    void GitRepoConditionalSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }

    bool GitRepoConditionalSegment::eval() {
        char buf[CWD_BUF_SIZE];
        if (!getcwd(buf, CWD_BUF_SIZE)) { return false; }
        string cwd(buf);

        struct stat stat_buf;
        while (cwd.length() > 0) {
            string temp = cwd + "/.git";
            if (stat(temp.c_str(), &stat_buf) == 0) { return true; }
            size_t pos = cwd.find_last_of("/");
            cwd        = cwd.substr(0, pos);
        }
        return false;
    }
} // namespace velocity::segment
