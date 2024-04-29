#pragma once
#include <iostream>
using namespace std;

class ControlUnit
{
private:
    float clock;

public:
    // Constructors
    ControlUnit()
    {
        Take_Input();
    }

    ControlUnit(float clockValue)
    {
        clock = clockValue;
    }

    void Take_Input()
    {
        bool flag = true;
        while (flag == true)
        {
            cout << "Enter the clock speed (3.1 GHz to 5.0 GHz)";
            cin >> clock;
            if (clock >= 3.1 && clock <= 5.0)
                flag = false;
        }
    }

    // Setters and Getters

    float getClock() const
    {
        return clock;
    }

    void setClock(float clockValue)
    {
        clock = clockValue;
    }
    void display()
    {
        cout << "Clock Speed: " << clock << endl;
    }
};
