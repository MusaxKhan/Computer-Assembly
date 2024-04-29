#pragma once
#include <iostream>
using namespace std;

void Cascading4(string& a)
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

class StorageDevice
{
private:
    string type;
    int capacity;
    double price;

public:
    StorageDevice()
    {
        Take_Input();
    }

    void Take_Input()
    {
        bool flag = true;
        while (flag == true)
        {
            cout << "Enter the type of storage device: (SSD or HDD)";
            cin >> type;
            Cascading4(type);
            if (type == "Ssd" || type == "Hdd")
                flag = false;
        }
        flag = true;
        while (flag == true)
        {
            cout << "Enter the capacity of the " << type << " : (128, 256, 512)";
            cin >> capacity;
            if (capacity == 128 || capacity == 256 || capacity == 512)
                flag = false;
        }
        price = capacity * 10;
    }

    StorageDevice(const string& typeVal, int capacityVal, double priceVal) : type(typeVal), capacity(capacityVal), price(priceVal) {}

    const string& getType() const
    {
        return type;
    }
    void setType(const string& typeVal)
    {
        type = typeVal;
    }

    int getCapacity() const
    {
        return capacity;
    }
    void setCapacity(int capacityVal)
    {
        capacity = capacityVal;
    }

    double getPrice() const
    {
        return price;
    }
    void setPrice(double priceVal)
    {
        price = priceVal;
    }
    void display()
    {
        cout << "Name of the device: " << type << endl;
        cout << "Size: " << capacity << " GB" << endl;
        cout << "Price: RS." << price << endl;
    }
};
