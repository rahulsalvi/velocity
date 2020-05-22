#include "EndSegment.h"
#include "ResetColor.h"

using std::make_shared;

EndSegment::EndSegment()
    : Segment(Format(make_shared<ResetColor>(), make_shared<ResetColor>()),
              "",
              "",
              0,
              false,
              false,
              false) {}

EndSegment::~EndSegment() {}

int EndSegment::length() {
    return 1; // to account for the space at the end
}

int EndSegment::trim() {
    return 0;
}

void EndSegment::expand() {}

void EndSegment::accept(Visitor& visitor) {
    visitor.visit(*this);
}
