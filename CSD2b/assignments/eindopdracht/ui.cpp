#include "ui.h"

//User input constructor and destructor
//--------------------------------------------------------------------------------------------//
UserInput::UserInput() {}

UserInput::~UserInput() {}


//validation user selection
//--------------------------------------------------------------------------------------------//
bool UserInput::validateSelection(std::string selection, 
    std::string selectionOptions[], int numOptions)
{
    //check if the selection is in the options, if so return true
    for (int i = 0; i < numOptions; ++i) {
        if(selection == selectionOptions[i]) {
            return true;
        }
    } 
    // if not return false
    return false;
}

//get the user input
//--------------------------------------------------------------------------------------------//
std::string UserInput::retrieveUserInput(std::string selectionOptions[], 
    int numOptions)
{
    //show user all the options
    std::cout << "Please choose between: ";
    for(int i = 0; i < numOptions - 1; i++) {
        std::cout << selectionOptions[i] << ", ";
    }
    //print last options
    std::cout << selectionOptions[numOptions - 1] << "." << std::endl;
    //retrieve and return choice
    std::string selection = "";
    std::cin >> selection;
    return selection;
}

//the class to get the user selection back
//--------------------------------------------------------------------------------------------//
std::string UserInput::retrieveUserSelection(std::string selectionOptions[], int numOptions) 
{
    bool noCorrectSelection = true;
    std::string userSelection = "";
    while(noCorrectSelection) {
        //let user choose between allowed options
        userSelection = retrieveUserInput(selectionOptions, numOptions);
        //cehck if the slection is correct
        noCorrectSelection = !validateSelection(userSelection, selectionOptions, numOptions);
        //if selection is not correct, give error message
        if(noCorrectSelection) {
            std::cout << "selection is incorrect please try again\n";
        }
    }
    return userSelection;
}

//number selection
//--------------------------------------------------------------------------------------------//
float UserInput::retrieveValueRange(float min, float max)
{
    std::string input;
    float value = 0;
    bool notInRange = true;

    while(notInRange) {
        std::cout << "Please enter a value between " << min << " and " << max
            << std::endl;
        // capture input
        std::cin >> input;
        //validate if string can transform to float
        try {
            value = std::stof(input);
            //validate range
            if(value >= min && value <= max) {
                notInRange = false;
            } else {
                std::cout << "out of range please try again" << std::endl;
            }
        } catch (const std::exception& e) {
            //no float as input
            std::cout << "Not a number, please try again" << std::endl;
        }
    }
    return value;
}