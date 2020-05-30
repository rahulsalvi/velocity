#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include <memory>
#include <string>
#include <vector>

#include "color/visitor/ColorVisitor.h"
#include "segment/Segment.h"
#include "segment/visitor/SegmentVisitor.h"
#include "style/visitor/StyleVisitor.h"

using std::shared_ptr;
using std::string;
using velocity::color::Color;
using velocity::color::ColorVisitor;
using velocity::style::Style;
using velocity::style::StyleVisitor;

namespace velocity::segment {
    class TextGenerator : public SegmentVisitor {
        public:
        TextGenerator(shared_ptr<ColorVisitor> color_generator,
                      shared_ptr<StyleVisitor> style_generator);
        virtual ~TextGenerator();

        virtual const string& text() const;

        protected:
        void emit_text(string text);
        void emit_foreground_code(const shared_ptr<Color> color);
        void emit_background_code(const shared_ptr<Color> color);
        void emit_style_start_code(const vector<shared_ptr<Style>>& styles);
        void emit_style_end_code(const vector<shared_ptr<Style>>& styles);

        private:
        string                   text_;
        shared_ptr<ColorVisitor> color_generator_;
        shared_ptr<StyleVisitor> style_generator_;
    };
} // namespace velocity::segment

#endif // TEXTGENERATOR_H
