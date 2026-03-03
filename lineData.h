// Joel Juntunen

#include <string>

#ifndef LINEDATA_H
#define LINEDATA_H

struct LineData{
    long unsigned int lineNumber;
    std::string line;
};

struct Options{
    bool lineNumbering = false;
    bool occurences = false;
    bool ignoreCase = false;
    bool reverseSearch = false;
};

#endif