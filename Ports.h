#pragma once
#include <iostream>
using namespace std;

void Cascading9(string& a)
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

class Port
{
private:
    string type;
    int baud_rate;

public:
    // Constructors

    Port()
    {
        Take_Input();
    }

    void Take_Input()
    {
        bool flag = true;
        while (flag == true)
        {
            cout << "Enter the type of the port you want (VGA--USB--HDMI--ETHERNET--AUDIO): ";
            cin >> type;
            Cascading9(type);
            if (type == "Vga" || type == "Usb" || type == "Hdmi" || type == "Ethernet" || type == "Audio")
                flag = false;
        }
        flag = true;
        while (flag == true)
        {
            cout << "Enter the valid BAUD rate of the port: (ranges from 1 Gbps to 20 Gbps)";
            cin >> baud_rate;
            if (baud_rate >= 1 && baud_rate <= 20)
                flag = false;
        }
    }


    Port(const string& portType, int rate) : type(portType), baud_rate(rate) {}

    // Setters and Getters

    const string& getType() const
    {
        return type;
    }
    void setType(const string& portType)
    {
        type = portType;
    }

    int getBaudRate() const
    {
        return baud_rate;
    }
    void setBaudRate(int rate)
    {
        baud_rate = rate;
    }
    void display()
    {
        cout << "Name of the port: " << type << endl;
        cout << "Baud Rate of the port: " << baud_rate <<" Gbps" << endl;
    }
};
