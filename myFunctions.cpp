// Joel Juntunen

// Include all needed header files.
#include "myFunctions.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>



// Reads all lines from the file.
void readTheLines(std::vector<std::string>* lines, const std::string* fileName){
   
    // Initialize the variables.
    std::string str;
    unsigned int counter = 0;

    // Open the text file.
    std::ifstream inputFile(*fileName);

    // Check if the file is open without errors.
    if (inputFile.is_open()){

        // Read the lines.
        while(!inputFile.eof() && std::getline(inputFile, str)){
            lines->push_back(str);
            counter++;
        }

        // tarkasta .fail() & .bad() !.eof() jälkeen

        inputFile.close();

        // std::cout << "Number of lines: " << lines->size() << std::endl;
    }
    else{
        throw std::ifstream::failure("File not found!");
    }
}

// Checks is the word part of the string.
std::vector<std::string> checkLines(std::vector<std::string>* lines, const std::string* searchWord){

    // Initialize the variables.
    std::vector<std::string> linesWithWord(0);

    // Check each line for searchWord. 
    for (int i = 0; i < lines->size(); i++){

        if (lines->at(i).find(*searchWord) != std::string::npos){            
            // Save the line.
            linesWithWord.push_back(lines->at(i));
        }
    }

    return linesWithWord;
}
