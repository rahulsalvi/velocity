#include "segment/visitor/ForwardGenerator.h"

namespace velocity::segment {
    ForwardGenerator::ForwardGenerator(shared_ptr<ColorVisitor> color_generator,
                                       shared_ptr<StyleVisitor> style_generator)
        : text_(""), color_generator_(color_generator), style_generator_(style_generator) {}

    ForwardGenerator::~ForwardGenerator() {}

    void ForwardGenerator::visit(StartSegment& segment) {
        text_ += segment.next()->format().background()->accept_background(*color_generator_);
        segment.next()->accept(*this);
    }

    void ForwardGenerator::visit(EndSegment& segment) {
        text_ += segment.format().foreground()->accept_foreground(*color_generator_);
        text_ += segment.format().style()->accept_start(*style_generator_);
        text_ += " ";
        text_ += segment.format().style()->accept_end(*style_generator_);
    }

    void ForwardGenerator::visit(TextSegment& segment) {
        text_ += segment.format().foreground()->accept_foreground(*color_generator_);
        text_ += " ";
        text_ += segment.format().style()->accept_start(*style_generator_);
        text_ += segment.text();
        text_ += segment.format().style()->accept_end(*style_generator_);
        text_ += " ";
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
            text_ += " ";
            text_ += segment.format().style()->accept_start(*style_generator_);
            text_ += *it;
            text_ += segment.format().style()->accept_end(*style_generator_);
            text_ += " ";
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
