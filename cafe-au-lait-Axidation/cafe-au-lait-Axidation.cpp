#include <iostream>
using namespace std;

void NewOrder()
{
    float Cappuccino;
    float Espresso;
    float Latte;
    float IcedCoffee;
    float Surcharge = 0;
    int NumCappuccino;
    int NumEspresso;
    int NumLatte;
    int NumIcedCoffee;

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
        printf("~-MENU-~ (inc. 10%% GST)\n1 - Cappuccino $%.2f\n2 - Esspresso $%.2f\n3 - Latte $%.2f\n4 - Iced Coffee $%.2f\n\n", Cappuccino, Espresso, Latte, IcedCoffee);

    }

    if (choice2 == "2")
    {

        Cappuccino = 3.465;
        Espresso = 2.59875;
        Latte = 2.8875;
        IcedCoffee = 2.8875;
        printf("~-MENU-~ (inc. 10%% GST + 5%% Surcharge)\n1 - Cappuccino $%.2f\n2 - Esspresso $%.2f\n3 - Latte $%.2f\n4 - Iced Coffee $%.2f\n\n", Cappuccino, Espresso, Latte, IcedCoffee);

    }

    printf("Please enter desired amount per item\n");
    printf("1: "); std::cin >> NumCappuccino;
    printf("2: "); std::cin >> NumEspresso;
    printf("3: "); std::cin >> NumLatte;
    printf("4: "); std::cin >> NumIcedCoffee;
    std::cout << "\n";

    if (choice2 == "2") Surcharge = 0.165 * NumCappuccino + 0.12375 * NumEspresso + 0.1375 * NumLatte + 0.1375 * NumIcedCoffee;

    float TotalPrice = NumCappuccino * Cappuccino + NumEspresso * Espresso + NumLatte * Latte + NumIcedCoffee * IcedCoffee;

    printf("| Quantity | Item        | Item Ex. GST | GST         |  Total  |\n");
    printf("| %-9.d| Cappuccino  | $3.00        | $0.30       | $%6.2f |\n", NumCappuccino, NumCappuccino * Cappuccino );
    printf("| %-9.d| Espresso    | $2.25        | $0.23       | $%6.2f |\n", NumEspresso, NumEspresso * Espresso);
    printf("| %-9.d| Latte       | $2.50        | $0.25       | $%6.2f |\n", NumLatte, NumLatte * Latte);
    printf("| %-9.d| Iced Coffee | $2.50        | $0.25       | $%6.2f |\n\n", NumIcedCoffee, NumIcedCoffee * IcedCoffee);
    printf(" Surcharge : $%-25.2f Overall Total : $%.2f \n", Surcharge, TotalPrice);

    float Tendered;
    printf("Amount Tendered: "); cin >> Tendered;

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

    while (restart != "n")
    {

        program();

        printf("\nRestart program? (y/n)\n");
        cin >> restart;
        printf("\n");

    }

};