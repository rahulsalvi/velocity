#include "OutputGenerator.h"

OutputGenerator::OutputGenerator() : text_("") {}

OutputGenerator::~OutputGenerator() {}

void OutputGenerator::visit(StartSegment& segment) {
    text_ += segment.next()->format().background()->ansi_code_background();
    segment.next()->accept(*this);
}

void OutputGenerator::visit(EndSegment& segment) {
    text_ += segment.format().foreground()->ansi_code_foreground();
    text_ += " ";
}

void OutputGenerator::visit(TextSegment& segment) {
    text_ += segment.format().foreground()->ansi_code_foreground();
    text_ += segment.text();
    text_ += segment.format().background()->ansi_code_foreground();
    text_ += segment.next()->format().background()->ansi_code_background();
    text_ += segment.separator();
    segment.next()->accept(*this);
}

const string& OutputGenerator::text() const {
    return text_;
}
