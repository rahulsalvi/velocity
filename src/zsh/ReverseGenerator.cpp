#include "zsh/ReverseGenerator.h"

namespace velocity::zsh {
    ReverseGenerator::ReverseGenerator() : text_("") {}

    ReverseGenerator::~ReverseGenerator() {}

    void ReverseGenerator::visit(StartSegment& segment) {
        text_ += segment.format().foreground()->accept_foreground(color_generator_);
        text_ += segment.format().background()->accept_background(color_generator_);
        segment.next()->accept(*this);
    }

    void ReverseGenerator::visit(EndSegment& segment) {
        text_ += segment.format().foreground()->accept_foreground(color_generator_);
        text_ += segment.format().background()->accept_background(color_generator_);
    }

    void ReverseGenerator::visit(TextSegment& segment) {
        text_ += segment.format().background()->accept_foreground(color_generator_);
        text_ += segment.separator();
        text_ += segment.format().foreground()->accept_foreground(color_generator_);
        text_ += segment.format().background()->accept_background(color_generator_);
        text_ += segment.text();
        segment.next()->accept(*this);
    }

    const string& ReverseGenerator::text() const { return text_; }
} // namespace velocity::zsh
