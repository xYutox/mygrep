// Joel Juntunen

#include "lineData.h"
#include <string>
#include <vector>

#ifndef DATAFUNCTIONS_H
#define DATAFUNCTIONS_H

std::vector<LineData> checkLines(std::vector<LineData>*, const std::string*);

void checkAndPrintLines(std::vector<LineData>*, const std::string*, std::vector<char>*);

void readTheLines(std::vector<std::string>*, const std::string*, const std::string*, const std::vector<char>*);

void printTheLines(std::vector<LineData>*, const std::string*, Options*);

#endif