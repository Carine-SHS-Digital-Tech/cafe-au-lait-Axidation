#include <iostream>
using namespace std;

void NewOrder()
{
    float Cappuccino = 0;
    float Espresso = 0;
    float Latte = 0;
    float IcedCoffee = 0;


    string choice2;
    std::cout << "Dine-In(1) or Take-Away(2)?\n";
    std::cin >> choice2;

    if (choice2 == "1");
    {

        Cappuccino = 3;
        Espresso = 2.25;
        Latte = 2.5;
        IcedCoffee = 2.5;

    }

    printf("~-MENU-~\nCappuccino $%.2f\nEsspresso $%.2f\nLatte $%.2f\nIced Coffee $%.2f\n", Cappuccino, Espresso, Latte, IcedCoffee);

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