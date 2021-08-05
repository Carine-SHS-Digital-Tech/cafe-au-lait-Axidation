#include <iostream>
using namespace std;

void NewOrder()
{
    float Cappuccino = 0;
    float Espresso = 0;
    float Latte = 0;
    float IcedCoffee = 0;
    string Item1;
    string Item2;
    string Item3;
    string Item4;

    string choice2;
    std::cout << "Dine-In(1) or Take-Away(2)?\n";
    std::cout << "*Take-Away incurs a 5% surcharge\n";
    std::cin >> choice2;
    std::cout << "\n";

    if (choice2 == "1")
    {

        Cappuccino = 3.3f;
        Espresso = 2.475f;
        Latte = 2.75f;
        IcedCoffee = 2.75f;
        printf("~-MENU-~ (inc. 10%% GST)\n1 - Cappuccino $%.2f\n2 - Esspresso $%.2f\n3 - Latte $%.2f\n4 - Iced Coffee $%.2f\n5 - None\n\n", Cappuccino, Espresso, Latte, IcedCoffee);

    }

    if (choice2 == "2")
    {

        Cappuccino = 3.465;
        Espresso = 2.59875;
        Latte = 2.8875;
        IcedCoffee = 2.8875;
        printf("~-MENU-~ (inc. 10%% GST + 5%% Surcharge)\n1 - Cappuccino $%.2f\n2 - Esspresso $%.2f\n3 - Latte $%.2f\n4 - Iced Coffee $%.2f\n5 - None\n\n", Cappuccino, Espresso, Latte, IcedCoffee);

    }

    printf("Please enter desired items (Up to 4)\n");
    printf("1: "); std::cin >> Item1;
    printf("2: "); std::cin >> Item2;
    printf("3: "); std::cin >> Item3;
    printf("4: "); std::cin >> Item4;

}

void program()
{

    string choice1;
    std::cout << "New order(1) or Daily Summary(2)?\n";
    std::cin >> choice1;
    std::cout << "\n";


    if (choice1 == "1") NewOrder();
    //if (choice1 == "1") DailySummary();

};

int main()
{

    string restart;

    while (restart != "N")
    {

        program();

        printf("\nRestart program? (Y/N)\n");
        cin >> restart;
        printf("\n");

    }

};