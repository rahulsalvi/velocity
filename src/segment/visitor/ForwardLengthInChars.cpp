#include "ForwardLengthInChars.h"
#include "utils.h"

using velocity::utils::utf8_strlen;

namespace velocity::segment {
    ForwardLengthInChars::ForwardLengthInChars() : length_(0) {}

    ForwardLengthInChars::~ForwardLengthInChars() {}

    int ForwardLengthInChars::length() const { return length_; }

    void ForwardLengthInChars::reset() { length_ = 0; }

    void ForwardLengthInChars::visit(StartSegment& segment) { segment.next()->accept(*this); }

    void ForwardLengthInChars::visit(EndSegment&) { length_ += 1; }

    void ForwardLengthInChars::visit(TextSegment& segment) {
        length_ += utf8_strlen(segment.text());
        length_ += utf8_strlen(segment.separator());
        length_ += 2; // to account for spaces
        segment.next()->accept(*this);
    }

    void ForwardLengthInChars::visit(CWDSegment& segment) {
        auto dirs = segment.directories();
        for (auto dir = dirs.begin(); dir != dirs.end(); ++dir) {
            length_ += 2;
            length_ += utf8_strlen(*dir);
            if (dir != dirs.end() - 1) { length_ += utf8_strlen(segment.inner_separator()); }
        }
        length_ += utf8_strlen(segment.outer_separator());
        segment.next()->accept(*this);
    }

    void ForwardLengthInChars::visit(GitInfoSegment& segment) {
        length_ += 1;
        if (segment.detached_head() && !segment.detached_head_indicator().empty()) {
            length_ += utf8_strlen(segment.detached_head_indicator());
            length_ += 1;
        } else if (!segment.branch_indicator().empty()) {
            length_ += utf8_strlen(segment.branch_indicator());
            length_ += 1;
        }
        length_ += utf8_strlen(segment.current_branch());
        length_ += 1;
        if (segment.has_untracked_files() && !segment.untracked_files_indicator().empty()) {
            length_ += utf8_strlen(segment.untracked_files_indicator());
            length_ += 1;
        }
        length_ += utf8_strlen(segment.separator());
        segment.next()->accept(*this);
    }

    void ForwardLengthInChars::visit(ConditionalSegment&) {}
} // namespace velocity::segment
