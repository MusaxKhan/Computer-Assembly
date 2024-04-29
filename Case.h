#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Storage.h"
#include "Power Supply.h"
#include "MotherBoard.h"
#include "Battery.h"

void Cascading3(string& a)
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

class Case
{
private:
    Type* A;
    StorageDevice* sdev;
    MotherBoard* mb;
    PowerSupply* psup;
    Battery* battery;
    string formFactor;
    string color;
    double price;

public:
    // Constructors
    Case(Type* ab, MotherBoard* m, StorageDevice* s, Battery* b, PowerSupply* ps)
    {
        A = ab;
        mb = m;
        sdev = s;
        battery = b;
        psup = ps;
        Take_Input();
        cout << A->device << endl;
        if (A->device == "P")
        {
            if (formFactor == "Atx")
                price = 10000;
            else if (formFactor == "Micro atx")
                price = 15000;
        }
    }

    void Take_Input()
    {
        bool flag = true;
        cout << endl << "Now we will design the case for your device: " << endl;
        while (flag)
        {
            cout << "Enter the form Factor of the case (ATX or Micro ATX): ";
            getline(cin, formFactor);
            Cascading3(formFactor);
            if (formFactor == "Atx" || formFactor == "Micro atx")
                flag = false;
        }
        cout << "Enter color of the case: ";
        cin >> color;
    }
    Case(const string& formFactorVal="", const string& colorVal="", double priceVal=0) : formFactor(formFactorVal), color(colorVal), price(priceVal) {}

    // Getters and Setters
    const string& getFormFactor() const
    {
        return formFactor;
    }
    void setFormFactor(const string& formFactorVal)
    {
        formFactor = formFactorVal;
    }

    const string& getColor() const
    {
        return color;
    }
    void setColor(const string& colorVal)
    {
        color = colorVal;
    }

    double getPrice() const
    {
        return price;
    }
    void setPrice(double priceVal)
    {
        price = priceVal;
    }

    StorageDevice* getStorageDevice() const
    {
        return sdev;
    }
    void setStorageDevice(StorageDevice* storageDevice)
    {
        sdev = storageDevice;
    }

    MotherBoard* getMotherBoard() const
    {
        return mb;
    }
    void setMotherBoard(MotherBoard* motherBoard)
    {
        mb = motherBoard;
    }

    PowerSupply* getPowerSupply() const
    {
        return psup;
    }
    void setPowerSupply(PowerSupply* powerSupply)
    {
        psup = powerSupply;
    }

    Battery* getBattery() const
    {
        return battery;
    }
    void setBattery(Battery* batteryVal)
    {
        battery = batteryVal;
    }
    void display() const
    {
        cout << "Form Factor: " << formFactor << endl;
        cout << "Color: " << color << endl;
        cout << "Price: $" << price << endl<<endl;
        cout << "Mother Board------>" << endl;
        mb->display();
        cout << endl << "Storage Devices---->" << endl;
        sdev->display();
        cout << endl<<"Battery----->" << endl;
        battery->display();
        cout << endl << "Power supply----->" << endl;
        psup->display();
    }
};
