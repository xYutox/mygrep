// Joel Juntunen

// Include all needed header files.
#include "fileFunctions.h"
#include <vector>
#include <string>
#include <fstream>

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
