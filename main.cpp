#include <iostream>
#include "Computer Assembly.h"

/*
Muhammad Musa Khan
Sec-E
23i-0526
Instructor: Marium Hida
TA: Muhammad Ali Naveed
*/


using namespace std;


int main()
{
    Type* A = new Type;
    cout << "-------------------------Device Designing-------------------------------" << endl << endl << endl << endl;
    cout << "Enter the type of computer you want: " << endl;
    cout << "Enter L for Laptop\nEnter P for PC" << endl;
    char a;
    cin >> a;
    if (a == 'P' || a == 'p')
    {
        A->device = "P";
    }
    else
    {
        A->device = "L";
    }
    cout << "First we will design the Mother board for your device" << endl << endl;
    string type;
    bool flag = true;
    if (A->device != "L")
    {
        while (flag == true)
        {
            cout << "Enter the type of processor you want for your PC : (Intel or AMD)";
            cin >> type;
            Cascading8(type);
            if (type == "Intel" || type == "Amd")
                flag = false;
        }
    }
    else
    {
        bool flag = true;
        while (flag == true)
        {
            cout << "Enter the type of processor you want for your Laptop: (Intel or AMD or MAC)";
            cin >> type;
            Cascading8(type);
            if (type == "Intel" || type == "Amd" || type == "Mac")
                flag = false;
        }
    }
    A->processor = type;
    cout << "For the Mother Board, we will first design the Central Processing Unit " << endl << endl;
    CPU* cpu = new CPU(A);
    cout << endl << "Now we will design the Physical memory of the Mother board" << endl << endl;
    PhysicalMemory* phy = new PhysicalMemory();
    GraphicsCard* gcard;
    NetworkCard* ncard;
    cout << "Do you want to install a graphics card in your motherboard: ";
    string ans;
    cin >> ans;
    Cascading5(ans);
    if (ans == "Yes")
    {
        gcard = new GraphicsCard(A);
    }
    else
    {
        //gcard = nullptr;
        gcard = new GraphicsCard("Zero");
        cout << "OK!" << endl
            << endl;
    }

    cout << "Do you want to install Network card: ";
    cin >> ans;
    Cascading(ans);
    if (ans == "Yes")
    {
        ncard = new NetworkCard();
    }
    else
    {
        //ncard = nullptr;
        ncard = new NetworkCard("Zero");
        cout << "OK!" << endl
            << endl;
    }
    int numPorts = 0;;
    cout << "Now we will have to install the ports in your Motherboard" << endl << endl;
    flag = true;
    while (flag == true)
    {
        cout << "Enter a valid number of ports you want (1-6)" << endl;
        cin >> numPorts;
        if (numPorts >= 1 && numPorts <= 6)
            flag = false;
    }
    Port* ports = new Port[numPorts];
       
    MotherBoard* mb = new MotherBoard(A, cpu, phy, gcard, ncard, ports, numPorts);
    cout << endl << "After designing the Mother board, now we will add the storage device in your device" << endl << endl;
    StorageDevice* sdev = new StorageDevice();
    cout << endl << "Now we will Design the Battery" << endl;
    Battery* bat = new Battery();
    cout << endl << "Now we will design the Power supply for your case" << endl << endl;
    PowerSupply* psup = new PowerSupply();


    Case* ca = new Case(A, mb, sdev, bat,psup);
    Computer* com = new Computer(A, ca);
    ComputerAssembly c(com);

    c.Display(A);
}