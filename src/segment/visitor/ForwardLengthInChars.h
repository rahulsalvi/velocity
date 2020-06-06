#ifndef FORWARDLENGTHINCHARS_H
#define FORWARDLENGTHINCHARS_H

#include "segment/CWDSegment.h"
#include "segment/ConditionalSegment.h"
#include "segment/EndSegment.h"
#include "segment/GitInfoSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/LengthMetric.h"

namespace velocity::segment {
    class ForwardLengthInChars : public LengthMetric {
        public:
        ForwardLengthInChars();
        ~ForwardLengthInChars();

        virtual int  length() const override;
        virtual void reset() override;

        virtual void visit(StartSegment& segment) override;
        virtual void visit(EndSegment& segment) override;
        virtual void visit(TextSegment& segment) override;
        virtual void visit(CWDSegment& segment) override;
        virtual void visit(GitInfoSegment& segment) override;
        virtual void visit(ConditionalSegment& segment) override;

        private:
        int length_;
    };
} // namespace velocity::segment

#endif // FORWARDLENGTHINCHARS_H
