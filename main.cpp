// Joel Juntunen

// Include all needed header files.
#include "inputChecker.cpp"
#include "dataFunctions.h"
#include "fileFunctions.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

// The projects main function.
int main(int argc, char* argv[]){

    // Initialize the variables.
    std::string userStr = "", searchWord = "", filename;
    std::vector<LineData> lines(0), linesWithWord(0);
    std::vector<char> options(0);
    std::size_t foundStr;

    // argument testing
    // std::cout << "Number of arguments: " << argc << " " << argv[0] << std::endl;

    try{
        switch (argc){
            
            // Without arguments.
            case (1):
                
                // Asks the user to give word to search and string to search from.
                std::cout << "Give a string from which to search for: ";
                userStr = inputChecker<std::string>();

                std::cout << "Give search string: ";
                searchWord = inputChecker<std::string>();

                // Checks if the word appears in string.
                foundStr = userStr.find(searchWord);             

                if(foundStr != std::string::npos){
                    std::cout << "\"" << searchWord << "\"" << " found in " << "\"" << userStr << "\"" << " in position " << foundStr << std::endl;
                }
                else{
                    std::cout << "\""<< searchWord << "\"" << " NOT found in " << "\"" << userStr << "\"" << std::endl;
                }
                break;
            
            // With word to search and filename.
            case(3):
                
                searchWord = argv[1];
                filename = argv[2];

                // Read the lines to the vector from the file.
                readTheLines(&lines, &filename); 
                
                linesWithWord = checkLines(&lines, &searchWord);

                // Print the lines containing the given word.
                for (LineData data : linesWithWord){
                    std::cout << data.line << std::endl;
                }

                break;
            
            // With options.
            case(4):
                      
                searchWord = argv[2];
                filename = argv[3];

                // Save the options to vector.
                for (int i = 0; i < strlen(argv[1]); i++){
                    options.push_back(tolower(argv[1][i]));
                }

                // Remove the "-o" option prefix.
                if (options.at(0) == '-' && options.at(1) == 'o'){
                    options.erase(options.begin(), options.begin() + 2);
                }
                else{
                    throw std::runtime_error("Incorrect options!");
                }

                // Read the lines
                readTheLines(&lines, &filename);

                checkAndPrintLines(&lines, &searchWord, &options);

                // Check the lines with options

                break;
            
            // With incorrect arguments. 
            default:
                throw std::runtime_error("Incorrect arguments!"); 
                break;            
        }
    }
    catch (const std::exception &e){
        
        std::cout << "An exception occurred. " << e.what() << std::endl;
        throw;
    }

    return 0;
}
