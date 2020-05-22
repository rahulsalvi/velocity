#ifndef UTILS_H
#define UTILS_H

#include <string>

using std::string;

int utf8_strlen(string& str) {
    int         len = 0;
    const char* s   = str.c_str();
    while (*s) { len += (*s++ & 0xC0) != 0x80; }
    return len;
}

#endif // UTILS_H
