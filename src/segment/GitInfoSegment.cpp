#include <algorithm>

#include "segment/GitInfoSegment.h"
#include "utils.h"

using velocity::utils::exec_exit_code;
using velocity::utils::exec_stdout;
using velocity::utils::file_contents;
using velocity::utils::get_cwd;
using velocity::utils::path_exists;

using std::remove;

namespace velocity::segment {
    GitInfoSegment::GitInfoSegment(Format clean_format,
                                   Format dirty_format,
                                   Format detached_head_format,
                                   string detached_head_indicator,
                                   string branch_indicator,
                                   string untracked_files_indicator,
                                   string separator,
                                   int    priority)
        : Segment(clean_format, "", separator, priority),
          clean_format_(clean_format),
          dirty_format_(dirty_format),
          detached_head_format_(detached_head_format),
          detached_head_indicator_(detached_head_indicator),
          branch_indicator_(branch_indicator),
          untracked_files_indicator_(untracked_files_indicator),
          detached_head_(false),
          has_untracked_files_(false),
          has_uncommitted_changes_(false) {}

    GitInfoSegment::~GitInfoSegment() {}

    void GitInfoSegment::accept(SegmentVisitor& visitor) { visitor.visit(*this); }

    const string& GitInfoSegment::detached_head_indicator() { return detached_head_indicator_; }

    const string& GitInfoSegment::branch_indicator() { return branch_indicator_; }

    const string& GitInfoSegment::untracked_files_indicator() { return untracked_files_indicator_; }

    const string& GitInfoSegment::current_branch() const { return current_branch_; }

    bool GitInfoSegment::detached_head() const { return detached_head_; }

    bool GitInfoSegment::has_untracked_files() const { return has_untracked_files_; }

    bool GitInfoSegment::has_uncommitted_changes() const { return has_uncommitted_changes_; }

    void GitInfoSegment::eval_current_branch() {
        string cwd = get_cwd();
        if (cwd.empty()) { return; }

        string head_file = "";
        while (!cwd.empty()) {
            string temp = cwd + "/.git/HEAD";
            if (path_exists(temp)) { head_file = temp; }
            size_t pos = cwd.find_last_of("/");
            cwd        = cwd.substr(0, pos);
        }
        if (head_file.empty()) { return; }
        string head_contents = file_contents(head_file);
        if (head_contents.empty()) { return; }

        size_t pos = head_contents.find("ref");
        if (pos != string::npos) {
            current_branch_ =
                head_contents.substr(string("ref: refs/heads/").length(), string::npos);
            current_branch_.erase(remove(current_branch_.begin(), current_branch_.end(), '\n'),
                                  current_branch_.end());
        } else {
            current_branch_ = head_contents.substr(0, 7);
            detached_head_  = true;
        }
    }

    void GitInfoSegment::eval_untracked_files() {
        if (detached_head_) { return; }
        string ret           = exec_stdout("git ls-files --exclude-standard --others");
        has_untracked_files_ = !ret.empty();
    }

    void GitInfoSegment::eval_uncommitted_changes() {
        if (detached_head_) { return; }
        exec_exit_code("git update-index --refresh");
        has_uncommitted_changes_ = exec_exit_code("git diff-index --quiet HEAD --");
    }

    void GitInfoSegment::eval_format() {
        if (detached_head_) {
            format_ = detached_head_format_;
        } else if (has_uncommitted_changes_ || has_untracked_files_) {
            format_ = dirty_format_;
        } else {
            format_ = clean_format_;
        }
    }
} // namespace velocity::segment
