#ifndef SEGMENTVISITOR_H
#define SEGMENTVISITOR_H

namespace velocity::segment {
    class StartSegment;
    class EndSegment;
    class TextSegment;

    class SegmentVisitor {
        public:
        ~SegmentVisitor(){};
        virtual void visit(StartSegment& segment) = 0;
        virtual void visit(EndSegment& segment)   = 0;
        virtual void visit(TextSegment& segment)  = 0;
    };
} // namespace velocity::segment

#endif // SEGMENTVISITOR_H
