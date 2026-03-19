#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class Bill
{
    string item;
    double rate;
    int Quantity;

public:
    Bill() : item(""), rate(0.0), qty(0) {}
    void setItem(string item)
    {
        this->item = item;
    }
    void setRate(double rate)
    {
        this->rate = rate;
    }
    void setQuantity(int quantity)
    {
        this->Quantity = quantity;
    }
    string getItem()
    {
        return this->item;
    }
    double getRate()
    {
        return this->rate;
    }
    int getQuantity()
    {
        return this->Quantity;
    }
};

void addBill(Bill &b)
{
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t1. Add" << endl;
        cout << "\t2. Close" << endl;
        cout << "\tEnter Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string item;
            double rate;
            int quantity;

            cout << "\tEnter the item Name : ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate of Item : ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter the Quantity of Item : ";
            cin >> quantity;
            b.setQuantity(quantity);

            ofstream fout("Bill.txt", ios::app);
            if (!fout)
            {
                cout << "\tError: File cannot be Open!" << endl;
            }
            else
            {
                fout << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl
                     << endl;
            }
            fout.close();
            cout << "\tItem Added Successfully" << endl;
            Sleep(3000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            Sleep(3000);
        }
    }
}

int main()
{

    return 0;
}