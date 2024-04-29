#pragma once
#include <iostream>
#include <string>
using namespace std;

void Cascading1(string& a)
{
    int l = a.size();
    if (a[0] >= 'a' && a[0] <= 'z')
        a[0] -= 32;
    for (int i = 1; i < l; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
    }
}

class MainMemory
{
private:
    int capacity;
    string technologyType;

public:
    // Constructors

    MainMemory()
    {
        Take_Input();
    }

    void Take_Input()
    {
        bool flag = true;
        while (flag == true)
        {
            cout << "For this, first we will design the main memory of the motherboard" << endl << endl;
            cout << "Enter a valid size of the Main Memory: (in GB's)";
            cin >> capacity;
            if (capacity % 4 == 0)
                flag = false;
        }
        flag = true;
        while (flag == true)
        {
            cout << "Enter the technology of the Main memory (Silicon or Semiconductor)" << endl;
            cin >> technologyType;
            Cascading1(technologyType);
            if (technologyType == "Silicon" || technologyType == "Semiconductor")
                flag = false;
        }
    }

    MainMemory(int cap, const std::string& tech="") : capacity(cap), technologyType(tech) {}

    // Setters and Getters

    int getCapacity() const
    {
        return capacity;
    }
    void setCapacity(int cap)
    {
        capacity = cap;
    }

    const std::string& getTechnologyType() const
    {
        return technologyType;
    }
    void setTechnologyType(const std::string& tech)
    {
        technologyType = tech;
    }
    void display()
    {
        cout << "Capacity of the main memory: " << capacity << endl;
        cout << "Technology Type: " << technologyType << endl;
    }
};