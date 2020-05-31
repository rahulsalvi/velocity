#ifndef GITINFOSEGMENT_H
#define GITINFOSEGMENT_H

#include <string>

#include "segment/Segment.h"
#include "segment/visitor/SegmentVisitor.h"

using std::string;

namespace velocity::segment {
    class GitInfoSegment : public Segment {
        public:
        GitInfoSegment(Format clean_format,
                       Format dirty_format,
                       Format detached_head_format,
                       string detached_head_indicator,
                       string branch_indicator,
                       string untracked_files_indicator,
                       string separator,
                       int    priority);
        virtual ~GitInfoSegment();

        virtual void accept(SegmentVisitor& visitor) override;

        virtual const string& detached_head_indicator();
        virtual const string& branch_indicator();
        virtual const string& untracked_files_indicator();

        virtual const string& current_branch() const;
        virtual bool          detached_head() const;
        virtual bool          has_untracked_files() const;
        virtual bool          has_uncommitted_changes() const;

        virtual void eval_current_branch();
        virtual void eval_untracked_files();
        virtual void eval_uncommitted_changes();
        virtual void eval_format();

        private:
        Format clean_format_;
        Format dirty_format_;
        Format detached_head_format_;

        string detached_head_indicator_;
        string branch_indicator_;
        string untracked_files_indicator_;

        string current_branch_;
        bool   detached_head_;
        bool   has_untracked_files_;
        bool   has_uncommitted_changes_;
    };
} // namespace velocity::segment

#endif // GITINFOSEGMENT_H
