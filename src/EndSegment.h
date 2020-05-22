#ifndef ENDSEGMENT_H
#define ENDSEGMENT_H

#include "Segment.h"
#include "Visitor.h"

class EndSegment : public Segment {
    public:
    EndSegment();
    virtual ~EndSegment();

    virtual int  length() override;
    virtual int  trim() override;
    virtual void expand() override;

    virtual void accept(Visitor& visitor) override;
};

#endif // ENDSEGMENT_H
