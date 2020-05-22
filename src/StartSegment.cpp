#include "StartSegment.h"
#include "ResetColor.h"

using std::make_shared;

StartSegment::StartSegment()
    : Segment(Format(make_shared<ResetColor>(), make_shared<ResetColor>()),
              "",
              "",
              0,
              false,
              false,
              false) {}

StartSegment::~StartSegment() {}

int StartSegment::length() {
    return 0;
}

int StartSegment::trim() {
    return 0;
}

void StartSegment::expand() {}

void StartSegment::accept(Visitor& visitor) {
    visitor.visit(*this);
}
