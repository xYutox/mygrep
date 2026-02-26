// Joel Juntunen

// Include all needed header files.
#include "fileFunctions.h"
#include "dataFunctions.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

/* Reads all lines from the file to the vector.
*
*   Variables:
*       - std::vector<LineData>* lines
*       - const std::string* fileName*
*/
void readTheLines(std::vector<LineData>* lines, const std::string* fileName){
   
    // Initialize the variables.
    std::string str;    
    int counter = 0;
    LineData data;

    // Open the text file.
    std::ifstream inputFile(*fileName);

    // Check if the file is open without errors.
    if (inputFile.is_open()){

        // Read the lines.
        while(!inputFile.eof() && std::getline(inputFile, str)){
            data.line = str;
            counter++;
            data.lineNumber = counter;

            lines->push_back(data);
        }

        // tarkasta .fail() & .bad(), !.eof():n jälkeen

        inputFile.close();
    }
    else{
        throw std::ifstream::failure("File not found!");
    }
}

/*
// Reads all the lines from the file with options.
void readTheLines(std::vector<std::string>* lines, const std::string* word, const std::string* fileName, const std::vector<char>* options){

    // Initialize the variables.
    std::string str;
    LineData data;
    std::vector<LineData> linesWithNumbering(0);
    int counter = 0;
    bool lineNumbering = false, ocurences = false;


    for (char option : *options){

        switch (option){

        case ('l'):
            lineNumbering = true;
            break;

        case ('o'):
            ocurences = true;            
            break;
        
        
        default:
            break;
        }
    }

    // Open the text file.
    std::ifstream inputFile(*fileName);

    if (lineNumbering){

        // Check if the file is open without errors.
        if (inputFile.is_open()){
            
            // Read the lines.
            while(!inputFile.eof() && std::getline(inputFile, str)){
                data.line = str;
                counter++;
                data.lineNumber = counter;

                linesWithNumbering.push_back(data);
            }
            
            inputFile.close();

            linesWithNumbering = checkLines(&linesWithNumbering, word);

            // Print the lines.
            if(ocurences){
                printTheLines(&linesWithNumbering, word);
            }
            else{
                
            }
        }
        else{
            throw std::ifstream::failure("File not found!");
        }
    }    
    else{
        //readTheLines(lines, fileName);

        //*lines = checkLines(lines, fileName);

        if(ocurences){
            
        }

    }
}
*/
