#ifndef SEGMENT_H
#define SEGMENT_H

#include <memory>
#include <string>

#include "Format.h"

using std::shared_ptr;
using std::string;

class Visitor;

class Segment {
    public:
    Segment(Format format,
            string text,
            string separator,
            int    priority,
            bool   trimmable,
            bool   expandable,
            bool   prunable)
        : format_(format),
          text_(text),
          separator_(separator),
          priority_(priority),
          trimmable_(trimmable),
          expandable_(expandable),
          prunable_(prunable) {}
    virtual ~Segment(){};

    const Format& format() { return format_; };
    const string& text() { return text_; };
    const string& separator() { return separator_; };
    int           priority() const { return priority_; }

    bool trimmable() const { return trimmable_; };
    bool expandable() const { return expandable_; };
    bool prunable() const { return prunable_; }

    virtual int  length() = 0;
    virtual int  trim()   = 0;
    virtual void expand() = 0;

    void set_next(shared_ptr<Segment> next) { next_ = next; }
    void set_prev(shared_ptr<Segment> prev) { prev_ = prev; }

    shared_ptr<Segment> next() { return next_; }
    shared_ptr<Segment> prev() { return prev_; }

    virtual void accept(Visitor& visitor) = 0;

    protected:
    shared_ptr<Segment> prev_;
    shared_ptr<Segment> next_;

    Format format_;
    string text_;
    string separator_;
    int    priority_;
    bool   trimmable_;
    bool   expandable_;
    bool   prunable_;
};

#endif // SEGMENT_H
