#ifndef FORWARDGENERATOR_H
#define FORWARDGENERATOR_H

#include <string>

#include "color/visitor/ColorVisitor.h"
#include "segment/CWDSegment.h"
#include "segment/ConditionalSegment.h"
#include "segment/EndSegment.h"
#include "segment/GitInfoSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/TextGenerator.h"
#include "style/visitor/StyleVisitor.h"

using std::string;
using velocity::color::ColorVisitor;
using velocity::style::StyleVisitor;

namespace velocity::segment {
    class ForwardGenerator : public TextGenerator {
        public:
        ForwardGenerator(shared_ptr<ColorVisitor> color_generator,
                         shared_ptr<StyleVisitor> style_generator);
        virtual ~ForwardGenerator();
        virtual void visit(StartSegment& segment);
        virtual void visit(EndSegment& segment);
        virtual void visit(TextSegment& segment);
        virtual void visit(CWDSegment& segment);
        virtual void visit(GitInfoSegment& segment);
        virtual void visit(ConditionalSegment& segment);
    };
} // namespace velocity::segment

#endif // FORWARDGENERATOR_H
