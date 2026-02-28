// Joel Juntunen

#include <string>

#ifndef LINEDATA_H
#define LINEDATA_H

struct LineData{
    int lineNumber;
    std::string line;
};

struct Options{
    bool lineNumbering = false;
    bool ocurences = false;
    bool ignoreCase = false;
    bool reverseSearch = false;
};

#endif