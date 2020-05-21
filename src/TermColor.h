#ifndef TERMCOLOR_H
#define TERMCOLOR_H

#include <unordered_map>

#include "Color.h"

using std::unordered_map;

static const unordered_map<string, int> color2code = {{"black", 30},
                                                      {"red", 31},
                                                      {"green", 32},
                                                      {"yellow", 33},
                                                      {"blue", 34},
                                                      {"magenta", 35},
                                                      {"cyan", 36},
                                                      {"white", 37},
                                                      {"brblack", 90},
                                                      {"brred", 91},
                                                      {"brgreen", 92},
                                                      {"bryellow", 93},
                                                      {"brblue", 94},
                                                      {"brmagenta", 95},
                                                      {"brcyan", 96},
                                                      {"brwhite", 97}};

class TermColor : public Color {
    public:
    TermColor(string color = "black");
    virtual ~TermColor();
    virtual string ansi_code_foreground() const override;
    virtual string ansi_code_background() const override;

    private:
    int foreground_;
    int background_;
};

#endif // TERMCOLOR_H
