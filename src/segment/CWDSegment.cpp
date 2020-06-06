#include "segment/CWDSegment.h"
#include "utils.h"

using velocity::utils::get_cwd;
using velocity::utils::get_homedir;

namespace velocity::segment {
    CWDSegment::CWDSegment(shared_ptr<Format> format,
                           int                priority,
                           string             outer_separator,
                           string             inner_separator)
        : DisplayedSegment(format, priority),
          outer_separator_(outer_separator),
          inner_separator_(inner_separator) {}

    CWDSegment::~CWDSegment() {}

    void CWDSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }

    const string& CWDSegment::outer_separator() const { return outer_separator_; }

    const string& CWDSegment::inner_separator() const { return inner_separator_; }

    const vector<string>& CWDSegment::directories() const { return directories_; }

    void CWDSegment::eval() {
        string cwd = get_cwd();
        if (cwd.empty()) { return; }
        string home = get_homedir();
        if (home.empty()) { return; }

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
