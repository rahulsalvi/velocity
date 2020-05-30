#ifndef REVERSEGENERATOR_H
#define REVERSEGENERATOR_H

#include <string>

#include "color/visitor/ColorVisitor.h"
#include "segment/CWDSegment.h"
#include "segment/ConditionalSegment.h"
#include "segment/EndSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/TextGenerator.h"
#include "style/visitor/StyleVisitor.h"

using std::string;
using velocity::color::ColorVisitor;
using velocity::style::StyleVisitor;

namespace velocity::segment {
    class ReverseGenerator : public TextGenerator {
        public:
        ReverseGenerator(shared_ptr<ColorVisitor> color_generator,
                         shared_ptr<StyleVisitor> style_generator);
        ~ReverseGenerator();
        virtual void visit(StartSegment& segment);
        virtual void visit(EndSegment& segment);
        virtual void visit(TextSegment& segment);
        virtual void visit(CWDSegment& segment);
        virtual void visit(ConditionalSegment& segment);
    };
} // namespace velocity::segment

#endif // REVERSEGENERATOR_H
