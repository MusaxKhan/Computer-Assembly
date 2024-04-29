#include <iostream>
#include "ALU.h"
#include "CU.h"
#include <string>
using namespace std;

class CPU
{
private:
    ALU alu;
    ControlUnit cu;

public:
    // Constructors
    CPU(Type* A) : alu(A), cu() {};

    CPU(const ALU& aluObj, const ControlUnit& cuObj) : alu(aluObj), cu(cuObj) {}

    // Setters and Getters

    ALU getALU() const
    {
        return alu;
    }
    ControlUnit getControlUnit() const
    {
        return cu;
    }

    void setALU(const ALU& aluObj)
    {
        alu = aluObj;
    }
    void setControlUnit(const ControlUnit& cuObj)
    {
        cu = cuObj;
    }
    void display()
    {
        alu.display();
        cout << endl;
        cu.display();
        cout << endl;
    }
};
