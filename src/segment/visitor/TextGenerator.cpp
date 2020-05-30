#include "segment/visitor/TextGenerator.h"

namespace velocity::segment {
    TextGenerator::TextGenerator(shared_ptr<ColorVisitor> color_generator,
                                 shared_ptr<StyleVisitor> style_generator)
        : color_generator_(color_generator), style_generator_(style_generator) {}

    TextGenerator::~TextGenerator() {}

    const string& TextGenerator::text() const { return text_; }

    void TextGenerator::emit_text(string text) { text_ += text; }

    void TextGenerator::emit_foreground_code(const shared_ptr<Color> color) {
        text_ += color->accept_foreground(*color_generator_);
    }

    void TextGenerator::emit_background_code(const shared_ptr<Color> color) {
        text_ += color->accept_background(*color_generator_);
    }

    void TextGenerator::emit_style_start_code(const vector<shared_ptr<Style>>& styles) {
        for (auto style : styles) { text_ += style->accept_start(*style_generator_); }
    }

    void TextGenerator::emit_style_end_code(const vector<shared_ptr<Style>>& styles) {
        for (auto style : styles) { text_ += style->accept_end(*style_generator_); }
    }
} // namespace velocity::segment
