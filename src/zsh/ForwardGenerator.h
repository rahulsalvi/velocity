#ifndef ZSHFORWARDGENERATOR_H
#define ZSHFORWARDGENERATOR_H

#include <string>

#include "segment/CWDSegment.h"
#include "segment/ConditionalSegment.h"
#include "segment/EndSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/SegmentVisitor.h"
#include "zsh/ColorCodeGenerator.h"

using std::string;
using velocity::segment::ConditionalSegment;
using velocity::segment::CWDSegment;
using velocity::segment::EndSegment;
using velocity::segment::SegmentVisitor;
using velocity::segment::StartSegment;
using velocity::segment::TextSegment;

namespace velocity::zsh {
    class ForwardGenerator : public SegmentVisitor {
        public:
        ForwardGenerator();
        ~ForwardGenerator();
        virtual void visit(StartSegment& segment);
        virtual void visit(EndSegment& segment);
        virtual void visit(TextSegment& segment);
        virtual void visit(CWDSegment& segment);
        virtual void visit(ConditionalSegment& segment);

        const string& text() const;

        private:
        string             text_;
        ColorCodeGenerator color_generator_;
    };
} // namespace velocity::zsh

#endif // ZSHFORWARDGENERATOR_H
