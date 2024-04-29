#pragma once
#include <iostream>
#include "Header.h"
using namespace std;

class PowerSupply
{
private:
    int wattage;
    string efficiencyRating;
    double price;

public:
    PowerSupply()
    {
        Take_Input();
    }

    void Take_Input()
    {
        bool flag = true;
        while (flag == true)
        {
            cout << "Of how many Watts you want the power supply (240 or 300 Watt)";
            cin >> wattage;
            if (wattage == 240 || wattage == 300)
                flag = false;
        }
        cout << "Battery Set with efficincy of 97% " << endl;
        efficiencyRating = "97%";
        price = 7000;
    }
    PowerSupply(int wattageVal, const string& efficiencyRatingVal, double priceVal) : wattage(wattageVal), efficiencyRating(efficiencyRatingVal), price(priceVal) {}

    int getWattage() const
    {
        return wattage;
    }
    void setWattage(int wattageVal)
    {
        wattage = wattageVal;
    }

    const string& getEfficiencyRating() const
    {
        return efficiencyRating;
    }
    void setEfficiencyRating(const string& efficiencyRatingVal)
    {
        efficiencyRating = efficiencyRatingVal;
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
        cout << "Wattage: " << wattage << endl;
        cout << "Efficiency Rating: " <<efficiencyRating<<endl;
        cout << "Price: RS." << price << endl;

    }
};