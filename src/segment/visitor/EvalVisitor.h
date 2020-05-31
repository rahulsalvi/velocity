#ifndef EVALVISITOR_H
#define EVALVISITOR_H

#include "segment/CWDSegment.h"
#include "segment/ConditionalSegment.h"
#include "segment/EndSegment.h"
#include "segment/GitInfoSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/SegmentVisitor.h"

namespace velocity::segment {
    class EvalVisitor : public SegmentVisitor {
        public:
        EvalVisitor();
        virtual ~EvalVisitor();
        virtual void visit(StartSegment& segment);
        virtual void visit(EndSegment& segment);
        virtual void visit(TextSegment& segment);
        virtual void visit(CWDSegment& segment);
        virtual void visit(GitInfoSegment& segment);
        virtual void visit(ConditionalSegment& segment);
    };
} // namespace velocity::segment

#endif // EVALVISITOR_H
