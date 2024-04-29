#pragma once
#include "Computer.h"
#include <iostream>
#include <string>
#include "Type.h"
using namespace std;

class ComputerAssembly
{
private:
    string type;
    Computer* comp;
    double totalPrice;

public:
    ComputerAssembly() : type(""), totalPrice(0) {}

    ComputerAssembly(Computer* com)
    {
        comp = com;

        totalPrice = comp->getCasing()->getMotherBoard()->getGcard()->getPrice() + comp->getCasing()->getMotherBoard()->getNcard()->getPrice() +
            comp->getCasing()->getPowerSupply()->getPrice() + comp->getCasing()->getPrice() + comp->getCasing()->getStorageDevice()->getPrice();
    }

    void Display(Type* A)
    {
        cout << "Device-----> ";
        if (A->device == "P")
            cout << "PC" << endl;
        else
            cout << "Laptop" << endl;
        comp->display();
        cout << endl << "Total Price---------->   RS." << totalPrice <<"\-" << endl;
        cout << "Thanku for your Cooperation.. Good bye" << endl;
    }
    ~ComputerAssembly()
    {
        delete comp;
    }

    // Getter and setter for type
    const string& getType() const
    {
        return type;
    }

    void setType(const string& typeVal)
    {
        type = typeVal;
    }

    // Getter and setter for totalPrice
    double getTotalPrice() const
    {
        return totalPrice;
    }

    void setTotalPrice(double priceVal)
    {
        totalPrice = priceVal;
    }
};
