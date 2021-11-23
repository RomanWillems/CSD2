#include <iostream>



struct CoffeeAmount {
    int CoffeeAmountInput;
    CoffeeAmount(){
        std::cout << "how much coffeespoons do you want?";
        std::cin >> CoffeeAmountInput; 
        } 
};
CoffeeAmount Amount;

//------------------------------------------//
class CoffeeMachine {
public:
    CoffeeMachine(std::string _coffee);
    ~CoffeeMachine();
    void makeCoffee();
    std::string coffee;
    float necessaryCoffeeAmount;
};

void CoffeeMachine::makeCoffee() {
    std::cout << coffee << std::endl;
}

CoffeeMachine::CoffeeMachine(std::string _coffee)
{
    coffee = _coffee;
}

CoffeeMachine::~CoffeeMachine()
{

}
//------------------------------------------//

int main() {
    std::cout << "amount is: " << Amount.CoffeeAmountInput << '\n';
    CoffeeMachine Espresso("making an espresso");
    CoffeeMachine Latte("making latte");

    Espresso.makeCoffee();
}