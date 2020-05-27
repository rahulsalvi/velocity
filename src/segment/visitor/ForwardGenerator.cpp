#include "segment/visitor/ForwardGenerator.h"

namespace velocity::segment {
    ForwardGenerator::ForwardGenerator(shared_ptr<ColorVisitor> color_generator)
        : text_(""), color_generator_(color_generator) {}

    ForwardGenerator::~ForwardGenerator() {}

    void ForwardGenerator::visit(StartSegment& segment) {
        text_ += segment.next()->format().background()->accept_background(*color_generator_);
        segment.next()->accept(*this);
    }

    void ForwardGenerator::visit(EndSegment& segment) {
        text_ += segment.format().foreground()->accept_foreground(*color_generator_);
        text_ += " ";
    }

    void ForwardGenerator::visit(TextSegment& segment) {
        text_ += segment.format().foreground()->accept_foreground(*color_generator_);
        text_ += segment.text();
        text_ += segment.format().background()->accept_foreground(*color_generator_);
        text_ += segment.next()->format().background()->accept_background(*color_generator_);
        text_ += segment.separator();
        segment.next()->accept(*this);
    }

    void ForwardGenerator::visit(CWDSegment& segment) {
        auto dirs            = segment.directories();
        auto inner_separator = segment.inner_separator();
        text_ += segment.format().foreground()->accept_foreground(*color_generator_);
        for (auto it = dirs.begin(); it != dirs.end(); ++it) {
            text_ += " " + *it + " ";
            if (it != dirs.end() - 1) { text_ += inner_separator; }
        }
        text_ += segment.format().background()->accept_foreground(*color_generator_);
        text_ += segment.next()->format().background()->accept_background(*color_generator_);
        text_ += segment.separator();
        segment.next()->accept(*this);
    }

    void ForwardGenerator::visit(ConditionalSegment&) {
        // TODO some error handling for this case
    }

    const string& ForwardGenerator::text() const { return text_; }
} // namespace velocity::segment
