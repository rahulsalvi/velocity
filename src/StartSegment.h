#ifndef STARTSEGMENT_H
#define STARTSEGMENT_H

#include "Segment.h"
#include "Visitor.h"

class StartSegment : public Segment {
    public:
    StartSegment();
    virtual ~StartSegment();

    virtual int  length() override;
    virtual int  trim() override;
    virtual void expand() override;

    virtual void accept(Visitor& visitor) override;
};

#endif // STARTSEGMENT_H
