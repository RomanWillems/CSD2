#include <iostream>

#pragma once

//create a user input class with the according functions
//--------------------------------------------------------------------------------------------//
class UserInput {
public:
    //constructor, destructor
    UserInput();
    ~UserInput();

    // if user selection is in array, return input
    std::string retrieveUserSelection(std::string selectionOptions[], int numOptions);
    
    // if user selectin is not in input: say "wrong input"
    bool validateSelection(std::string selection, std::string selectionOptions[], int NumOptions);

    //give back the user input
    std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

    //number user input with range
    float retrieveValueRange(float min, float max);    

protected:
    int numOptions;
    std::string selection;

};
//--------------------------------------------------------------------------------------------//