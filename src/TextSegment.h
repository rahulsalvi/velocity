#ifndef TEXTSEGMENT_H
#define TEXTSEGMENT_H

#include "Segment.h"
#include "Visitor.h"

class TextSegment : public Segment {
    public:
    TextSegment(Format format, string text, string separator, int priority);
    virtual ~TextSegment();

    virtual int  length() override;
    virtual int  trim() override;
    virtual void expand() override;

    virtual void accept(Visitor& visitor) override;
};

#endif // TEXTSEGMENT_H
