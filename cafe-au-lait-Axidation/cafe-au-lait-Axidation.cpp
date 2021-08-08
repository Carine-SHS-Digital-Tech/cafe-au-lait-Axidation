#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Global variables
int T_DineIn = 0;
int T_TakeOut = 0;
int T_Order = 0;
int T_NumCappuccino = 0;
int T_NumEspresso = 0;
int T_NumLatte = 0;
int T_NumIcedCoffee = 0;
int T_Cups = 0;
float T_TotalGST = 0;
float T_TotalPrice = 0;

//Create the summary csv file
ofstream DailySummaryCSV("DailySummary.csv");

//Code that runs when "New Order" is selected
void NewOrder()
{
    //Local variables
    int DineIn = 0;
    int TakeOut = 0;
    int NumCappuccino = 0;
    int NumEspresso = 0;
    int NumLatte = 0;
    int NumIcedCoffee = 0;
    int Cups = 0;
    float TotalGST = 0;
    float TotalPrice = 0;
    float Cappuccino;
    float Espresso;
    float Latte;
    float IcedCoffee;
    float Surcharge = 0;
    float Tendered;
    float Change;

    //Determines whether or not surcharge is applied
    string choice2;
    cout << "Dine-In(1) or Take-Away(2)?\n";
    cout << "*Take-Away incurs a 5% surcharge\n";
    cin >> choice2;
    if (choice2 != "1" && choice2 != "2") { printf("\nAn error occured."); return; }
    cout << "\n";

    if (choice2 == "1") //Surcharge not applied
    {

        Cappuccino = 3.3f;
        Espresso = 2.475f;
        Latte = 2.75f;
        IcedCoffee = 2.75f;
        printf("~-MENU-~ (inc. 10%% GST)\n1 - Cappuccino $%.2f\n2 - Esspresso $%.2f\n3 - Latte $%.2f\n4 - Iced Coffee $%.2f\n\n", Cappuccino, Espresso, Latte, IcedCoffee);
        DineIn = 1;

    }

    if (choice2 == "2") //Surcharge applied
    {

        Cappuccino = 3.465;
        Espresso = 2.59875;
        Latte = 2.8875;
        IcedCoffee = 2.8875;
        printf("~-MENU-~ (inc. 10%% GST + 5%% Surcharge)\n1 - Cappuccino $%.2f\n2 - Esspresso $%.2f\n3 - Latte $%.2f\n4 - Iced Coffee $%.2f\n\n", Cappuccino, Espresso, Latte, IcedCoffee);
        TakeOut = 1;

    }

    //Order input
    printf("Please enter desired amount per item\n");
    printf("1: "); cin >> NumCappuccino;
    if (NumCappuccino < 0) { printf("\nAn error occured."); return; };
    printf("2: "); cin >> NumEspresso;
    if (NumCappuccino < 0) { printf("\nAn error occured."); return; };
    printf("3: "); cin >> NumLatte;
    if (NumCappuccino < 0) { printf("\nAn error occured."); return; };
    printf("4: "); cin >> NumIcedCoffee;
    if (NumCappuccino < 0) { printf("\nAn error occured."); return; };
    cout << "\n";

    //Calculates surcharge if applicable
    if (choice2 == "2") Surcharge = 0.165 * NumCappuccino + 0.12375 * NumEspresso + 0.1375 * NumLatte + 0.1375 * NumIcedCoffee;

    //Calculates total order price
    TotalPrice = NumCappuccino * Cappuccino + NumEspresso * Espresso + NumLatte * Latte + NumIcedCoffee * IcedCoffee;

    //Prints order summary
    printf("| Quantity | Item        | Single Item Ex. GST | GST         |  Total  |\n");
    printf("| %-9.d| Cappuccino  | $3.00               | $0.30       | $%-6.2f |\n", NumCappuccino, NumCappuccino * Cappuccino);
    printf("| %-9.d| Espresso    | $2.25               | $0.23       | $%-6.2f |\n", NumEspresso, NumEspresso * Espresso);
    printf("| %-9.d| Latte       | $2.50               | $0.25       | $%-6.2f |\n", NumLatte, NumLatte * Latte);
    printf("| %-9.d| Iced Coffee | $2.50               | $0.25       | $%-6.2f |\n\n", NumIcedCoffee, NumIcedCoffee * IcedCoffee);
    printf(" Surcharge : $%-6.2f Overall Total : $%6.2f \n\n", Surcharge, TotalPrice);
    
    //Input for amount tendered
    printf("Amount Tendered ($): "); cin >> Tendered; cout << "\n\n\n";

    //Calculates Change
    Change = Tendered - TotalPrice;

    //Prints sales receipt
    printf("SALES RECEIPT -\n");
    printf("_____---------------*****~~~| Cafe au Lait |~~~*****---------------_____\n");
    printf("| Quantity | Item        | Single Item Ex. GST | GST         |  Total  |\n");
    printf("| %-9.1d| Cappuccino  | $3.00               | $0.30       | $%-6.2f |\n", NumCappuccino, NumCappuccino * Cappuccino);
    printf("| %-9.1d| Espresso    | $2.25               | $0.23       | $%-6.2f |\n", NumEspresso, NumEspresso * Espresso);
    printf("| %-9.1d| Latte       | $2.50               | $0.25       | $%-6.2f |\n", NumLatte, NumLatte * Latte);
    printf("| %-9.1d| Iced Coffee | $2.50               | $0.25       | $%-6.2f |\n\n", NumIcedCoffee, NumIcedCoffee * IcedCoffee);
    printf(" Surcharge : $%-6.2f Overall Total : $%-6.2f\n", Surcharge, TotalPrice);
    printf(" Tendered : $%-6.2f Change : $%-6.2f\n\n", Tendered, Change);

    //Calculates total order GST
    TotalGST = 0.3 * NumCappuccino + 0.225 * NumEspresso + 0.25 * NumLatte + 0.25 * NumIcedCoffee;

    //Calculates total items purchased
    Cups = NumCappuccino + NumEspresso + NumLatte + NumIcedCoffee;

    //Updates global variables with new data
    T_DineIn += DineIn;
    T_TakeOut += TakeOut;
    T_Order += 1;
    T_NumCappuccino += NumCappuccino;
    T_NumEspresso += NumEspresso;
    T_NumLatte += NumLatte;
    T_NumIcedCoffee += NumIcedCoffee;
    T_Cups = T_Cups + Cups;
    T_TotalGST += TotalGST;
    T_TotalPrice += (TotalPrice - TotalGST);

    return;

};

//Code that runs when "Daily Summary" is selected
void DailySummary()
{
    //Prints summary to console
    printf("\nTotal Dine-In    |  %d", T_DineIn);
    printf("\nTotal Take-Away  |  %d", T_TakeOut);
    printf("\nTotal Orders     |  %d", T_Order);
    printf("\nTotal Cappuccino |  %d", T_NumCappuccino);
    printf("\nTotal Espresso   |  %d", T_NumEspresso);
    printf("\nTotal Latte      |  %d", T_NumLatte);
    printf("\nTotal Iced Coffee|  %d", T_NumIcedCoffee);
    printf("\nTotal Cups Sold  |  %d", T_Cups);
    printf("\nTotal GST        | $%.2f", T_TotalGST);
    printf("\nTotal Income     | $%.2f\n\n", T_TotalPrice);

    //Prints summary to csv file
    DailySummaryCSV << "Total Dine-In, " << T_DineIn;
    DailySummaryCSV << "\nTotal Take-Away, " << T_TakeOut;
    DailySummaryCSV << "\nTotal Orders, " << T_Order;
    DailySummaryCSV << "\nTotal Cappuccino, " << T_NumCappuccino;
    DailySummaryCSV << "\nTotal Espresso, " << T_NumEspresso;
    DailySummaryCSV << "\nTotal Latte, " << T_NumLatte;
    DailySummaryCSV << "\nTotal Iced Coffee, " << T_NumIcedCoffee;
    DailySummaryCSV << "\nTotal Cups Sold, " << T_Cups;
    DailySummaryCSV << "\nTotal GST, $" << setprecision(2) << fixed << T_TotalGST;
    DailySummaryCSV << "\nTotal Income, $" << setprecision(2) << fixed << T_TotalPrice;

    return;
}

void main()
{

    //Local variables
    string restart;
    string choice1;

    //Allows code to run infinitely
    while (restart != "n")
    {

        //Selection of function
        cout << "New order(1) or Daily Summary(2)?\n";
        cin >> choice1;
        cout << "\n";

        if (choice1 == "1") NewOrder();
        if (choice1 == "2") DailySummary();

        //Error function if input invalid
        if (choice1 != "1" && choice1 != "2") { printf("\nAn error occured."); return; }

        printf("\nBack to Start? (y/n)\n");
        cin >> restart;
        printf("\n");

        if (restart != "y") break;

    }

    return;

};