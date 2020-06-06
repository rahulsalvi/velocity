#include "segment/visitor/ReverseGenerator.h"

namespace velocity::segment {
    ReverseGenerator::ReverseGenerator(shared_ptr<ColorVisitor> color_generator,
                                       shared_ptr<StyleVisitor> style_generator)
        : TextGenerator(color_generator, style_generator) {}

    ReverseGenerator::~ReverseGenerator() {}

    void ReverseGenerator::visit(StartSegment& segment) {
        emit_foreground_code(segment.format()->foreground());
        emit_background_code(segment.format()->background());
        emit_style_start_code(segment.format()->style());
        emit_text(" ");
        emit_style_end_code(segment.format()->style());
        segment.next()->accept(*this);
    }

    void ReverseGenerator::visit(EndSegment& segment) {
        emit_foreground_code(segment.format()->foreground());
        emit_background_code(segment.format()->background());
    }

    void ReverseGenerator::visit(TextSegment& segment) {
        emit_foreground_code(segment.format()->background());
        emit_text(segment.separator());
        emit_foreground_code(segment.format()->foreground());
        emit_background_code(segment.format()->background());
        emit_style_start_code(segment.format()->style());
        emit_text(segment.text());
        emit_style_end_code(segment.format()->style());
        emit_text(" ");
        segment.next()->accept(*this);
    }

    void ReverseGenerator::visit(CWDSegment& segment) {
        auto dirs = segment.directories();

        emit_foreground_code(segment.format()->background());
        emit_text(segment.outer_separator());
        emit_foreground_code(segment.format()->foreground());
        emit_background_code(segment.format()->background());
        for (auto dir = dirs.begin(); dir != dirs.end(); ++dir) {
            emit_text(" ");
            emit_style_start_code(segment.format()->style());
            emit_text(*dir);
            emit_style_end_code(segment.format()->style());
            emit_text(" ");
            if (dir != dirs.end() - 1) { emit_text(segment.inner_separator()); }
        }
        segment.next()->accept(*this);
    }

    void ReverseGenerator::visit(GitInfoSegment& segment) {
        emit_foreground_code(segment.format()->background());
        emit_text(segment.separator());
        emit_foreground_code(segment.format()->foreground());
        emit_background_code(segment.format()->background());

        emit_text(" ");
        if (segment.detached_head() && !segment.detached_head_indicator().empty()) {
            emit_style_start_code(segment.format()->style());
            emit_text(segment.detached_head_indicator());
            emit_style_end_code(segment.format()->style());
            emit_text(" ");
        } else if (!segment.branch_indicator().empty()) {
            emit_style_start_code(segment.format()->style());
            emit_text(segment.branch_indicator());
            emit_style_end_code(segment.format()->style());
            emit_text(" ");
        }
        emit_style_start_code(segment.format()->style());
        emit_text(segment.current_branch());
        emit_style_end_code(segment.format()->style());
        emit_text(" ");
        if (segment.has_untracked_files() && !segment.untracked_files_indicator().empty()) {
            emit_style_start_code(segment.format()->style());
            emit_text(segment.untracked_files_indicator());
            emit_style_end_code(segment.format()->style());
            emit_text(" ");
        }
        segment.next()->accept(*this);
    }

    void ReverseGenerator::visit(ConditionalSegment&) {
        // TODO some error handling for this case
    }
} // namespace velocity::segment
