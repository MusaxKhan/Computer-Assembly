#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Case.h"

class Computer
{
private:
    Case* casing;

public:
    // Default Constructor
    Computer(Type* A, Case* ca)
    {
        casing = ca;
    }

    // Parameterized Constructor
    Computer(Case* newCasing)
    {
        casing = newCasing;
    }

    // Getter for casing
    Case* getCasing() const
    {
        return casing;
    }

    // Setter for casing
    void setCasing(Case* newCasing)
    {
        casing = newCasing;
    }
    void display()
    {
        cout << endl << "Casing---->" << endl;
        casing->display();
    }
};
