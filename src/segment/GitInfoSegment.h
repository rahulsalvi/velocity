#ifndef GITINFOSEGMENT_H
#define GITINFOSEGMENT_H

#include <string>

#include "segment/DisplayedSegment.h"
#include "segment/visitor/SegmentVisitor.h"

using std::string;

namespace velocity::segment {
    class GitInfoSegment : public DisplayedSegment {
        public:
        GitInfoSegment(shared_ptr<Format> clean_format,
                       shared_ptr<Format> dirty_format,
                       shared_ptr<Format> detached_head_format,
                       int                priority,
                       string             detached_head_indicator,
                       string             branch_indicator,
                       string             untracked_files_indicator,
                       string             separator);
        virtual ~GitInfoSegment();

        virtual shared_ptr<Format> format() const override;

        virtual const string& detached_head_indicator() const;
        virtual const string& branch_indicator() const;
        virtual const string& untracked_files_indicator() const;
        virtual const string& separator() const;

        virtual const string& current_branch() const;
        virtual bool          detached_head() const;
        virtual bool          has_untracked_files() const;
        virtual bool          has_uncommitted_changes() const;

        virtual void eval_current_branch();
        virtual void eval_untracked_files();
        virtual void eval_uncommitted_changes();

        virtual void accept(SegmentVisitor& visitor) override;

        private:
        shared_ptr<Format> clean_format_;
        shared_ptr<Format> dirty_format_;
        shared_ptr<Format> detached_head_format_;

        string detached_head_indicator_;
        string branch_indicator_;
        string untracked_files_indicator_;
        string separator_;

        string current_branch_;
        bool   detached_head_;
        bool   has_untracked_files_;
        bool   has_uncommitted_changes_;
    };
} // namespace velocity::segment

#endif // GITINFOSEGMENT_H
