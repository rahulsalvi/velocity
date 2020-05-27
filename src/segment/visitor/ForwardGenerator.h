#ifndef FORWARDGENERATOR_H
#define FORWARDGENERATOR_H

#include <string>

#include "color/visitor/ColorVisitor.h"
#include "segment/CWDSegment.h"
#include "segment/ConditionalSegment.h"
#include "segment/EndSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/SegmentVisitor.h"
#include "style/visitor/StyleVisitor.h"

using std::string;
using velocity::color::ColorVisitor;
using velocity::style::StyleVisitor;

namespace velocity::segment {
    class ForwardGenerator : public SegmentVisitor {
        public:
        ForwardGenerator(shared_ptr<ColorVisitor> color_generator,
                         shared_ptr<StyleVisitor> style_generator);
        ~ForwardGenerator();
        virtual void visit(StartSegment& segment);
        virtual void visit(EndSegment& segment);
        virtual void visit(TextSegment& segment);
        virtual void visit(CWDSegment& segment);
        virtual void visit(ConditionalSegment& segment);

        const string& text() const;

        private:
        string                   text_;
        shared_ptr<ColorVisitor> color_generator_;
        shared_ptr<StyleVisitor> style_generator_;
    };
} // namespace velocity::segment

#endif // FORWARDGENERATOR_H
