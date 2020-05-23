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

    void ReverseGenerator::visit(CWDSegment& segment) {
        auto dirs            = segment.directories();
        auto inner_separator = segment.inner_separator();

        text_ += segment.format().background()->accept_foreground(color_generator_);
        text_ += segment.separator();
        text_ += segment.format().foreground()->accept_foreground(color_generator_);
        text_ += segment.format().background()->accept_background(color_generator_);
        for (auto it = dirs.begin(); it != dirs.end(); ++it) {
            text_ += " " + *it + " ";
            if (it != dirs.end() - 1) { text_ += inner_separator; }
        }
        segment.next()->accept(*this);
    }

    void ReverseGenerator::visit(ConditionalSegment&) {
        // TODO some error handling for this case
    }

    const string& ReverseGenerator::text() const { return text_; }
} // namespace velocity::zsh
