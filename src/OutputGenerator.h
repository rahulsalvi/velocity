#ifndef OUTPUTGENERATOR_H
#define OUTPUTGENERATOR_H

#include <string>

#include "EndSegment.h"
#include "StartSegment.h"
#include "TextSegment.h"
#include "Visitor.h"

using std::string;

class OutputGenerator : public Visitor {
    public:
    OutputGenerator();
    ~OutputGenerator();
    virtual void visit(StartSegment& segment);
    virtual void visit(EndSegment& segment);
    virtual void visit(TextSegment& segment);

    const string& text() const;

    private:
    string text_;
};

#endif // OUTPUTGENERATOR_H
