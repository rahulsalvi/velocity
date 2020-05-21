#ifndef RESETCOLOR_H
#define RESETCOLOR_H

#include "Color.h"

class ResetColor : Color {
    public:
    ResetColor();
    virtual ~ResetColor();
    virtual string ansi_code_foreground() const override;
    virtual string ansi_code_background() const override;
};

#endif // RESETCOLOR_H
