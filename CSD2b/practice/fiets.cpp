#include <iostream>

//-----------------------------------------------------------------------------//
class Stear
{
public:
    Stear();
    ~Stear();
    float stearing_height;
    int stearing_width;
};

Stear::Stear()
{
    stearing_height = 5.5;
    stearing_width = 6;
    std::cout << "stearing hight  "<< stearing_height << std::endl;
    std::cout << "stearing width "<< stearing_width << std::endl;

}

Stear::~Stear()
{

}

//-----------------------------------------------------------------------------//
class Wheel
{
public:
    Wheel();
    ~Wheel();
    float diameter_front;
    int diameter_back;

};

Wheel::Wheel()
{
    diameter_front = 10.3;
    diameter_back = 11;
    std::cout << "front wheel "<< diameter_front << std::endl;
    std::cout << "back wheel "<< diameter_back << std::endl;
}

Wheel::~Wheel()
{

}
//-----------------------------------------------------------------------------//

class Bike
{
public:
    Bike();
    ~Bike();
    Wheel front_wheel;
    Stear stearing_height;
};

Bike::Bike()
{
    std::cout << "Constructor Called" << std::endl;
}

Bike::~Bike()
{
    std::cout << "Deconstructor Called" << std::endl;
}

//-----------------------------------------------------------------------------//

int main()
{

    Bike bike;

}
