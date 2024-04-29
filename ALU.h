#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Computer Assembly.h"
#include "Type.h"

void Cascading8(string& a)
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

class ALU
{
private:
    Type* A;
    string type;
    int NoOfAdders;
    int NoOfSubtractors;
    int NoOfRegisters;
    int sizeOfRegisters;

public:
    // Constructors

    ALU() : type(""), NoOfAdders(0), NoOfRegisters(0), NoOfSubtractors(0), sizeOfRegisters(0) {}

    ALU(Type* ty)
    {
        A = ty;
        if (A->device== "P")
        {
            if (A->processor == "Intel")
            {
                NoOfAdders = 16;
                NoOfSubtractors = 20;
                NoOfRegisters = 16;
                sizeOfRegisters = 86;
                A->processor = "I";
                type = A->processor;
            }
            else if (A->processor == "Amd")
            {
                NoOfAdders = 20;
                NoOfSubtractors = 16;
                NoOfRegisters = 32;
                sizeOfRegisters = 64;
                A->processor = "A";
                type = A->processor;
            }
        }
        else if (A->device == "L")
        {
            if (A->processor == "Intel")
            {
                NoOfAdders = 16;
                NoOfSubtractors = 20;
                NoOfRegisters = 16;
                sizeOfRegisters = 86;
                A->processor = "I";
                type = A->processor;
            }
            else if (A->processor == "Amd")
            {
                NoOfAdders = 20;
                NoOfSubtractors = 16;
                NoOfRegisters = 32;
                sizeOfRegisters = 64;
                A->processor = "A";
                type = A->processor;
            }
            else if (A->processor == "Mac")
            {
                NoOfAdders = 16;
                NoOfSubtractors = 32;
                NoOfRegisters = 32;
                sizeOfRegisters = 86;
                A->processor = "M";
                type = A->processor;
            }
        }
    }

    ALU(int adders, int subtractors, int registers, int size)
    {
        NoOfAdders = adders;
        NoOfSubtractors = subtractors;
        NoOfRegisters = registers;
        sizeOfRegisters = size;
    }


    // Setters and Getters

    int getNoOfAdders() const
    {
        return NoOfAdders;
    }

    string getType() const
    {
        return type;
    }

    int getNoOfSubtractors() const
    {
        return NoOfSubtractors;
    }

    int getNoOfRegisters() const
    {
        return NoOfRegisters;
    }

    int getSizeOfRegisters() const
    {
        return sizeOfRegisters;
    }

    void setNoOfAdders(int adders)
    {
        NoOfAdders = adders;
    }

    void setNoOfSubtractors(int subtractors)
    {
        NoOfSubtractors = subtractors;
    }

    void setNoOfRegisters(int registers)
    {
        NoOfRegisters = registers;
    }

    void setSizeOfRegisters(int size)
    {
        sizeOfRegisters = size;
    }

    void display() const
    {
        cout << "Processor Type: " << type << endl;
        cout << "Number of Adders: " << NoOfAdders << endl;
        cout << "Number of Subtractors: " << NoOfSubtractors << endl;
        cout << "Number of Registers: " << NoOfRegisters << endl;
        cout << "Size of Registers: " << sizeOfRegisters << endl;
    }
};
