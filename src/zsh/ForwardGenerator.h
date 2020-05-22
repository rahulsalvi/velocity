#ifndef ZSHFORWARDGENERATOR_H
#define ZSHFORWARDGENERATOR_H

#include <string>

#include "color/visitor/ANSICodeGenerator.h"
#include "segment/EndSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/SegmentVisitor.h"

using std::string;
using velocity::color::ANSICodeGenerator;
using velocity::segment::EndSegment;
using velocity::segment::SegmentVisitor;
using velocity::segment::StartSegment;
using velocity::segment::TextSegment;

namespace velocity::segment::zsh {
    class ForwardGenerator : public SegmentVisitor {
        public:
        ForwardGenerator();
        ~ForwardGenerator();
        virtual void visit(StartSegment& segment);
        virtual void visit(EndSegment& segment);
        virtual void visit(TextSegment& segment);

        const string& text() const;

        private:
        string            text_;
        ANSICodeGenerator color_generator_;
    };
} // namespace velocity::segment::zsh

#endif // ZSHFORWARDGENERATOR_H
