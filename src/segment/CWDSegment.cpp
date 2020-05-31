#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

#include "segment/CWDSegment.h"

#ifndef CWD_BUF_SIZE
#define CWD_BUF_SIZE 1024
#endif

namespace velocity::segment {
    CWDSegment::CWDSegment(Format format,
                           int    priority,
                           string outer_separator,
                           string inner_separator)
        : Segment(format, priority),
          outer_separator_(outer_separator),
          inner_separator_(inner_separator) {}

    CWDSegment::~CWDSegment() {}

    void CWDSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }

    const string& CWDSegment::outer_separator() const { return outer_separator_; }

    const string& CWDSegment::inner_separator() const { return inner_separator_; }

    const vector<string>& CWDSegment::directories() const { return directories_; }

    void CWDSegment::eval() {
        char buf[CWD_BUF_SIZE];
        // TODO some better error handling would be nice
        if (!getcwd(buf, CWD_BUF_SIZE)) { return; }
        const char* homedir;
        if (!(homedir = getenv("HOME"))) {
            struct passwd* pw = getpwuid(getuid());
            if (pw) { homedir = pw->pw_dir; }
        }
        if (!homedir) { return; }
        string cwd(buf);
        string home(homedir);
        if (cwd.find(home) == 0) {
            cwd.erase(0, home.length());
            cwd = "~" + cwd;
        } else {
            cwd.erase(0, 1); // remove leading '/'
        }
        size_t start = 0;
        size_t end;
        do {
            end = cwd.find("/", start);
            directories_.push_back(cwd.substr(start, end - start));
            start = end + 1;
        } while (end != string::npos);

        if (directories_.size() == 1 && directories_[0] == "") { directories_[0] = "/"; }
    }
} // namespace velocity::segment
