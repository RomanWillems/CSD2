#include <iostream>

#pragma once

class UserInput {
public:
    UserInput();
    ~UserInput();

    //  if user selection is in array, return input
    std::string retrieveUserSelection(std::string selectionOptions[], int numOptions);
    // if user selectin is not in input: say "wrong input"
    bool validateSelection(std::string selection, std::string selectionOptions[], int NumOptions);

    std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

    float retrieveValueRange(float min, float max);    

protected:
    int numOptions;
    std::string selection;

};