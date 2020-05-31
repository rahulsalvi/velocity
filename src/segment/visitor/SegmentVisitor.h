#ifndef SEGMENTVISITOR_H
#define SEGMENTVISITOR_H

namespace velocity::segment {
    class StartSegment;
    class EndSegment;
    class TextSegment;
    class CWDSegment;
    class GitInfoSegment;
    class ConditionalSegment;

    class SegmentVisitor {
        public:
        ~SegmentVisitor() {}
        virtual void visit(StartSegment& segment)       = 0;
        virtual void visit(EndSegment& segment)         = 0;
        virtual void visit(TextSegment& segment)        = 0;
        virtual void visit(CWDSegment& segment)         = 0;
        virtual void visit(GitInfoSegment& segment)     = 0;
        virtual void visit(ConditionalSegment& segment) = 0;
    };
} // namespace velocity::segment

#endif // SEGMENTVISITOR_H
