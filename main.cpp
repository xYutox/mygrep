// Joel Juntunen

// Include all needed header files.
#include "inputChecker.cpp"
#include <iostream>
#include <vector>

// The projects main function.
int main(int argc, char* argv[]){

    // Initialize the variables.
    std::string userStr = "", userWord = "";
    std::vector<std::string> lines(0);

    // argument testing
    // std::cout << "Number of arguments: " << argc << " " << argv[0] << std::endl;
    // std::cout << "hello tite!" << std::endl;

    try{
        switch (argc){
            
            // Without arguments.
            case (1):
                std::cout << "Give a string from which to search for: ";
                userStr = inputChecker<std::string>();

                lines.push_back(userStr);

                std::cout << "Give search string: ";
                userWord = inputChecker<std::string>();                

                std::size_t foundStr = lines[0].find(userWord);

                if(foundStr != std::string::npos){
                    std::cout << " \"" << userWord << "\" " << " found in " << " \"" << userStr << "\" " << " in position " << foundStr << std::endl;
                }
                else{
                    std::cout << " \""<< userWord << "\" " << " NOT found in " << " \"" << userStr << "\" " << std::endl;
                }
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
