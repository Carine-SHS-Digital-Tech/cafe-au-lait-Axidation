#include <iostream>
using namespace std;

void NewOrder()
{
    float Cappuccino = 0;
    float Espresso = 0;
    float Latte = 0;
    float IcedCoffee = 0;
    string ch2surcharge = "";


    string choice2;
    std::cout << "Dine-In(1) or Take-Away(2)?\n";
    std::cout << "*Take-Away incurs a 5% surcharge\n";
    std::cin >> choice2;

    if (choice2 == "1")
    {

        Cappuccino = 3.3f;
        Espresso = 2.475f;
        Latte = 2.75f;
        IcedCoffee = 2.75f;

    }

    if (choice2 == "2")
    {

        Cappuccino = 3.465;
        Espresso = 2.59875;
        Latte = 2.8875;
        IcedCoffee = 2.8875;
        ch2surcharge = " + 5 % Surcharge";

    }

    printf("~-MENU-~ (inc. 10% GST%s)\nCappuccino $%.2f\nEsspresso $%.2f\nLatte $%.2f\nIced Coffee $%.2f\n", ch2surcharge, Cappuccino, Espresso, Latte, IcedCoffee);

}

void program()
{

    string choice1;
    std::cout << "Daily Summary(1) or New order(2)?\n";
    std::cin >> choice1;



    //if (choice1 == "1") DailySummary();
    if (choice1 == "2") NewOrder();

    
};

int main()
{
    program();
};