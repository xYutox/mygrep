// Joel Juntunen

// Include all needed header files.
#include "inputChecker.cpp"
#include "myFunctions.h"
#include <iostream>
#include <vector>

// The projects main function.
int main(int argc, char* argv[]){

    // Initialize the variables.
    std::string userStr = "", searchWord = "", filename;
    std::vector<std::string> lines(0);
    std::size_t foundStr;

    // argument testing
    std::cout << "Number of arguments: " << argc << " " << argv[0] << std::endl;

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

                // Reads the file lines to vector.
                readTheLines(&lines, &filename);
                
                break;
            
            // With incorrect arguments. 
            default:
                throw std::runtime_error("Incorrect arguments!"); 
                break;            
        }


    }
    catch (const std::exception &e)
    {
        std::cout << "An exception occurred. " << e.what() << std::endl;
        throw;
    }

    return 0;
}
