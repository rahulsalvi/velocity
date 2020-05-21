#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <cstdint>

#include "Color.h"

class RGBColor : public Color {
    public:
    RGBColor(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0);
    virtual ~RGBColor();
    virtual string ansi_code_foreground() const override;
    virtual string ansi_code_background() const override;

    private:
    string ansi_code_base() const;

    uint8_t r_;
    uint8_t g_;
    uint8_t b_;
};

#endif // RGBCOLOR_H
