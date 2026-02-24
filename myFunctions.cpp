// Joel Juntunen

// Include all needed header files.
#include "myFunctions.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

// Checks is the word part of the string.
std::size_t checkStrings(std::string* line, std::string* searchWord){

    // 
    return line->find(*searchWord);
}

// 
void readTheLines(std::vector<std::string>* lines, const std::string* fileName){
   
    //
    std::string str;
    unsigned int counter = 0;

    // Open the text file.
    std::ifstream inputFile(*fileName);

    if (inputFile.good()){

        // Read the lines.
        while(!inputFile.eof() &&  std::getline(inputFile, str)){
            lines->push_back(str);
            counter++;
        }

        inputFile.close();

        std::cout << "Number of lines: " << lines->size() << std::endl;
    }
    else{
        throw std::ifstream::failure("File not found!");
    }
}
