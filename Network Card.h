#pragma once
#include <iostream>
using namespace std;

void Cascading6(string& a)
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

class NetworkCard
{
private:
    string type;
    int speed;
    double price;

public:
    NetworkCard()
    {
        Take_Input();
    }

    void Take_Input()
    {
        bool flag = true;
        while (flag == true)
        {
            cout << endl << "Which type of Network Card you want to intall? (WIFI or Ethernet)";
            cin >> type;
            Cascading6(type);
            if (type == "Wifi")
            {
                flag = false;
                cout << "WIFI Network card has been installed" << endl;
                type = "WIFI";
                price = 1500;
            }
            else if (type == "Ethernet")
            {
                flag = false;
                cout << "Ethernet Network card has been installed" << endl;
                type = "Ethernet";
                price = 1000;
            }
        }
        flag = true;
        while (flag == true)
        {
            cout << "Enter the speed of the Card: (1 to 10 Mbps)";
            cin >> speed;
            if (speed >= 1 && speed <= 10)
                flag = false;
        }
    }
    NetworkCard(const string a) : type(""), speed(0), price(0) {}
    NetworkCard(const string& typeVal, int speedVal, double priceVal) : type(typeVal), speed(speedVal), price(priceVal) {}

    const string& getType() const
    {
        return type;
    }
    void setType(const string& typeVal)
    {
        type = typeVal;
    }

    int getSpeed() const
    {
        return speed;
    }
    void setSpeed(int speedVal)
    {
        speed = speedVal;
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
        cout << "Type: " << type << endl;
        cout << "Speed: " << speed << " Mbps" << endl;
        cout << "Price: RS." << price << endl;
    }
};