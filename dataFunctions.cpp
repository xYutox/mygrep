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

// Checks is the word part of the string.
std::vector<LineData> checkLines(std::vector<LineData>* lines, const std::string* searchWord){

    // Initialize the variables.
    std::vector<LineData> linesWithWord(0);

    // Check each line for searchWord. 
    for (long unsigned int i = 0; i < lines->size(); i++){

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
void checkAndPrintLines(std::vector<LineData>* lines, const std::string* searchWord, std::vector<char>* options, const std::string* filename){

    // Initialize the variables.
    std::vector<LineData> linesWithWord(0);
    std::string wordToLower, lineToLower;
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
                opt.occurences = true;
                break;

            case ('i'):
                opt.ignoreCase = true;
                break;

            case('r'):
                opt.reverseSearch = true;
        }
    }

    // Save the word to variable and convert the word to lower case.
    if(opt.ignoreCase){
        wordToLower = *searchWord;
        transform(wordToLower.begin(), wordToLower.end(), wordToLower.begin(), ::tolower);
    }

    // Resersed search
    if (opt.reverseSearch){

        if (opt.ignoreCase){
            
            for (long unsigned int i = 0; i < lines->size(); i++){            
                
                // Convert line to lower case letters.          
                lineToLower = lines->at(i).line;
    
                transform(lineToLower.begin(), lineToLower.end(), lineToLower.begin(),::tolower);
                
                // Save the lines without the word.
                if (lineToLower.find(wordToLower) == std::string::npos){
                    linesWithWord.push_back(lines->at(i));
                }
            }
        }
        else{        
            // Without ignore case.
            for (long unsigned int i = 0; i < lines->size(); i++){
        
                // Save the lines without the word.
                if (lines->at(i).line.find(*searchWord) == std::string::npos){
                    linesWithWord.push_back(lines->at(i));
                }
            }
        }
    }
    // Not reversed
    else{
        if(opt.ignoreCase){          
            
            for (long unsigned int i = 0; i < lines->size(); i++){            
                
                // Convert line to lower case letters.          
                lineToLower = lines->at(i).line;    
                transform(lineToLower.begin(), lineToLower.end(), lineToLower.begin(),::tolower);
                
                if (lineToLower.find(wordToLower) != std::string::npos){
                    linesWithWord.push_back(lines->at(i));
                }
            }
        }
        else{        
            // Without ignore case.
            for (long unsigned int i = 0; i < lines->size(); i++){
        
                if (lines->at(i).line.find(*searchWord) != std::string::npos){
                    linesWithWord.push_back(lines->at(i));
                }
            }
        }

    }

    // Print the lines.
    if (linesWithWord.size() != 0){
        printTheLines(&linesWithWord, searchWord, &opt);
    }
    else{
        std::cout << "\""<< *searchWord << "\"" << " NOT found in " << "\"" << *filename << "\"" << std::endl;
    }
}

// Prints the lines with options.
void printTheLines(std::vector<LineData>* lines, const std::string* word, Options *opt){

    // Print the lines with word.
    if (opt->lineNumbering){
        for (long unsigned int i = 0; i < lines->size(); i++){
            std::cout << lines->at(i).lineNumber << ": " << lines->at(i).line << std::endl;
        }
    }
    else{
        for(LineData data : *lines){
            std::cout << data.line << std::endl;
        }
    }

    // Print the occurences.
    if(opt->occurences){

        if (opt->reverseSearch){
            std::cout << "\nOccurences of lines NOT containing \"" << *word << "\": " << lines->size() << std::endl;

        }
        else{
            std::cout << "\nOccurences of lines containing \"" << *word << "\": " << lines->size() << std::endl;
        }
    }
}
