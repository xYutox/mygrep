// Joel Juntunen

// Include all needed header files.
#include "dataFunctions.h"
#include "lineData.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>


// // Checks is the word part of the string.
// std::vector<std::string> checkLines(std::vector<std::string>* lines, const std::string* searchWord){

//     // Initialize the variables.
//     std::vector<std::string> linesWithWord(0);

//     // Check each line for searchWord. 
//     for (int i = 0; i < lines->size(); i++){

//         if (lines->at(i).find(*searchWord) != std::string::npos){            
//             // Save the line.
//             linesWithWord.push_back(lines->at(i));
//         }
//     }

//     return linesWithWord;
// }

// Checks is the word part of the string.
std::vector<LineData> checkLines(std::vector<LineData>* lines, const std::string* searchWord){

    // Initialize the variables.
    std::vector<LineData> linesWithWord(0);

    // Check each line for searchWord. 
    for (int i = 0; i < lines->size(); i++){

        // Save the lines with the word.
        if (lines->at(i).line.find(*searchWord) != std::string::npos){          
            linesWithWord.push_back(lines->at(i));
        }
    }

    return linesWithWord;
}

/* Checks is the word part of the string with options.
*
* Parameters:
*   - std::vector<LineData>* lines
*   - const std::string* searchWord
*   - std::vector<char>* options
*
*/
void checkTheLines(std::vector<LineData>* lines, const std::string* searchWord, std::vector<char>* options){

    // Initialize the variables.
    std::vector<LineData> linesWithWord(0);
    Options opt;

    if (options->size() == 0){
        throw std::runtime_error("Incorrect options!");
    }

    // Check the options.
    for (char option : *options){

        switch (option){

            case ('l'):
                opt.lineNumbering = true;
                break;

            case ('o'):
                opt.ocurences = true;
                break;

            default:
                break;
        }
    }

    for (int i = 0; i < lines->size(); i++){

        if (lines->at(i).line.find(*searchWord) != std::string::npos){
            linesWithWord.push_back(lines->at(i));
        }
    }

    // Print the lines.
    printTheLines(&linesWithWord, searchWord, &opt);
}

/*
*
*
*
*
*
*/
void printTheLines(std::vector<LineData>* lines, const std::string* word, Options *opt){

    // Print the lines with word.
    if (opt->lineNumbering){
        for (int i = 0; i < lines->size(); i++){
            std::cout << lines->at(i).lineNumber << ": " << lines->at(i).line << std::endl;
        }
    }
    else{
        for(LineData data : *lines){
            std::cout << data.line << std::endl;
        }
    }

    // Print the ocurences.
    if(opt->ocurences){
        std::cout << "\nOcurences of lines containing \"" << *word << "\": " << lines->size() << std::endl;
    }
}
