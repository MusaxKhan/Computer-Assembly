#pragma once
#include <iostream>
using namespace std;

class Battery
{
private:
    int capacity;

public:
    Battery()
    {
        Take_Input();
    }

    Battery(int capacityVal) : capacity(capacityVal) {}

    int getCapacity() const
    {
        return capacity;
    }
    void setCapacity(int capacityVal)
    {
        capacity = capacityVal;
    }
    void display() const
    {
        cout << "Battery Capacity: " << capacity << " mAh" << endl;
    }

    void Take_Input()
    {
        bool flag = true;
        while (flag == true)
        {
            cout << "Enter the capacity of the battery: (2000-5000 mAh)";
            cin >> capacity;
            if (capacity >= 2000 && capacity <= 5000)
                flag = false;
        }
    }
};
