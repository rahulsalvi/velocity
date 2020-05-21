#ifndef COLOR_H
#define COLOR_H

#include <string>

using std::string;

class Color {
    public:
    virtual ~Color(){};
    virtual string ansi_code_foreground() const = 0;
    virtual string ansi_code_background() const = 0;
};

#endif // COLOR_H
