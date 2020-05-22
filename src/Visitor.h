#ifndef VISITOR_H
#define VISITOR_H

class StartSegment;
class EndSegment;
class TextSegment;

class Visitor {
    public:
    ~Visitor(){};
    virtual void visit(StartSegment& segment) = 0;
    virtual void visit(EndSegment& segment)   = 0;
    virtual void visit(TextSegment& segment)  = 0;
};

#endif // VISITOR_H
