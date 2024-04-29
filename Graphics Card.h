#pragma once
#include <iostream>
#include "ALU.h"
#include "Type.h"
using namespace std;

void Cascading2(string& a)
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

class GraphicsCard
{
private:
    Type* A;
    string brand;
    int memorySize;
    double price;

public:
    GraphicsCard(Type* ty)
    {
        A = ty;
        if (A->processor == "I" || A->processor=="A")
        {
            Take_Input();
        }
        else
        {
            cout << "As you have the Apple device so integrated GPU is already attached" << endl;
            brand = "Apple GPU";
            memorySize = 8;
            price = 470000;
        }
    }
    void Take_Input()
    {
        bool flag = true;
        while (flag == true)
        {
            cout << "Enter the Brand of the Graphics Card: (NVIDIA or AMD)";
            cin >> brand;
            Cascading2(brand);
            if (brand == "Nvidia" || brand == "Amd")
                flag = false;
        }
        flag = true;
        while (flag == true)
        {
            cout << "Enter the size of the graphics card: (1 GB - 16 GB)";
            cin >> memorySize;
            if (memorySize >= 1 && memorySize <= 16)
                flag = false;
        }
        if (brand == "Nvidia")
        {
            price = memorySize * 25000;
        }
        else if (brand == "Amd")
            price = memorySize * 19000;
    }

    GraphicsCard(const string& brandVal="", int memorySizeVal=0, double priceVal=0) : brand(brandVal), memorySize(memorySizeVal), price(priceVal) {}

    const string& getBrand() const
    {
        return brand;
    }
    void setBrand(const string& brandVal)
    {
        brand = brandVal;
    }

    int getMemorySize() const
    {
        return memorySize;
    }
    void setMemorySize(int memorySizeVal)
    {
        memorySize = memorySizeVal;
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
        cout << "Brand: " << brand << endl;
        cout << "Memory size: " << memorySize << endl;
        cout << "Price : RS." << price << endl;
    }
};
