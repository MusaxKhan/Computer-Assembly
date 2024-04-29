#pragma once
#include <iostream>
using namespace std;

class Type
{
public:
	string processor;
	string device;
	Type(string pr = "", string de = "") :processor(pr), device(de) {}
};