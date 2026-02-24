// Joel Juntunen

// Include all needed header files.
#include <iostream>
#include <typeinfo>
#include <string>

// Checks the user input with given variable type.
template <typename T> 
std::string inputChecker(){
    
    T input;    

    std::getline(std::cin, input);
    
    if(input.empty() || isspace(input[0])){
        throw std::runtime_error("Empty string!");
    }
    else{
        return input;
    }   
}

