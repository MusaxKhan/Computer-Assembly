#pragma once
#include <iostream>
using namespace std;

class PhysicalMemory
{
private:
    int capacity;

public:
    PhysicalMemory()
    {
        Take_Input();
    }

    void Take_Input()
    {
        bool falg = true;
        while (falg == true)
        {
            cout << "Enter a valid size of the RAM: (in GB's) {2 GB, 4 GB, 8 GB, etc)";
            cin >> capacity;
            if (capacity % 4 == 0 || capacity == 2)
                falg = false;
        }
    }

    PhysicalMemory(int cap) : capacity(cap) {}

    int getCapacity() const
    {
        return capacity;
    }
    void setCapacity(int cap)
    {
        capacity = cap;
    }
    void display()
    {
        cout << "Capacity: " << capacity << endl;
    }
};