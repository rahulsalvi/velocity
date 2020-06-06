#include "segment/visitor/EvalVisitor.h"

namespace velocity::segment {
    EvalVisitor::EvalVisitor() {}

    EvalVisitor::~EvalVisitor() {}

    void EvalVisitor::visit(StartSegment& segment) { segment.next()->accept(*this); }

    void EvalVisitor::visit(EndSegment&) {}

    void EvalVisitor::visit(TextSegment& segment) { segment.next()->accept(*this); }

    void EvalVisitor::visit(CWDSegment& segment) {
        segment.eval();
        segment.next()->accept(*this);
    }

    void EvalVisitor::visit(GitInfoSegment& segment) {
        segment.eval_current_branch();
        segment.eval_uncommitted_changes();
        segment.eval_untracked_files();
        segment.next()->accept(*this);
    }

    void EvalVisitor::visit(ConditionalSegment& segment) {
        shared_ptr<Segment> branch_taken =
            (segment.eval() ? segment.true_segment() : segment.false_segment());
        segment.prev()->set_next(branch_taken);
        branch_taken->set_prev(segment.prev());
        branch_taken->accept(*this);
    }
} // namespace velocity::segment
