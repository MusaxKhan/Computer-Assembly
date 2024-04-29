#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Main Memory.h"
#include "Network Card.h"
#include "CPU.h"
#include "Ports.h"
#include "Physical Memory.h"
#include "Graphics Card.h"

void Cascading5(string& a)
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

class MotherBoard
{
private:
    GraphicsCard* gcard;
    NetworkCard* ncard;
    MainMemory mm;
    Port* ports;
    int numPorts;
    CPU* cpu;
    PhysicalMemory* pm;

public:
    // Constructors

    MotherBoard(Type* A, CPU* c, PhysicalMemory* p, GraphicsCard* g, NetworkCard* n, Port* po, int a)
    {
        cpu = c;
        pm = p;
        gcard = g;
        ncard = n;
        ports = po;
        numPorts = a;
    }

    MotherBoard(const MainMemory& memory, int num, const Port* portsArray) : mm(memory), numPorts(num)
    {
        ports = new Port[num];
        for (int i = 0; i < num; ++i)
        {
            ports[i] = portsArray[i];
        }
    }

    // Getters and Setters

    PhysicalMemory* getPhysicalMemory() const
    {
        return pm;
    }
    void setPhysicalMemory(PhysicalMemory* memory)
    {
        if (pm != memory)
        {
            delete pm;
            pm = memory;
        }
    }

    CPU* getCPU() const
    {
        return cpu;
    }
    void setCPU(CPU* processor)
    {
        if (cpu != processor)
        {
            delete cpu;
            cpu = processor;
        }
    }

    const MainMemory& getMainMemory() const
    {
        return mm;
    }
    void setMainMemory(const MainMemory& memory)
    {
        mm = memory;
    }

    const Port* getPorts() const
    {
        return ports;
    }
    void setPorts(int num, const Port* portsArray)
    {
        delete[] ports;
        numPorts = num;
        ports = new Port[num];
        for (int i = 0; i < num; ++i)
        {
            ports[i] = portsArray[i];
        }
    }

    int getNumPorts() const
    {
        return numPorts;
    }
    void setNumPorts(int num)
    {
        numPorts = num;
    }

    GraphicsCard* getGcard() const
    {
        return gcard;
    }
    NetworkCard* getNcard() const
    {
        return ncard;
    }
    void display()
    {
        cout << endl << "Main Memeory------>" << endl;
        mm.display();
        cout << endl << "CPU------> " << endl;
        cpu->display();
        cout << endl << "Physical Memeory----->" << endl;
        pm->display();
        if (gcard->getPrice()!=0)
        {
            cout << endl << "Graphics Card------>" << endl;
            gcard->display();
        }
        if (ncard->getPrice()!=0)
        {
            cout << endl << "Network Card----->" << endl;
            ncard->display();
        }
        cout << endl << "Number of Ports: " << numPorts << endl;
        for (int i = 0;i < numPorts;i++)
        {
            cout << "Port " << i + 1 << "------>" << endl;
            ports[i].display();
        }

    }
};