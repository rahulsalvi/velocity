#ifndef ZSHREVERSEGENERATOR_H
#define ZSHREVERSEGENERATOR_H

#include <string>

#include "ANSICodeGenerator.h"
#include "EndSegment.h"
#include "SegmentVisitor.h"
#include "StartSegment.h"
#include "TextSegment.h"

using std::string;
using velocity::color::ANSICodeGenerator;
using velocity::segment::EndSegment;
using velocity::segment::SegmentVisitor;
using velocity::segment::StartSegment;
using velocity::segment::TextSegment;

namespace velocity::segment::zsh {
    class ReverseGenerator : public SegmentVisitor {
        public:
        ReverseGenerator();
        ~ReverseGenerator();
        virtual void visit(StartSegment& segment);
        virtual void visit(EndSegment& segment);
        virtual void visit(TextSegment& segment);

        const string& text() const;

        private:
        string            text_;
        ANSICodeGenerator color_generator_;
    };
} // namespace velocity::segment::zsh

#endif // ZSHREVERSEGENERATOR_H
