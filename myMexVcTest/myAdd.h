#pragma once
//#include "pch.h"
#include<iostream>
#include"myAdd2.h"

class myAdd
{
public:
	double addFunc(double m1, double m2);
	//double addFunc(double m1, double m2)
	//{
	//	double m = 10 * m1 + m2;
	//	return m;
	//}

private:
	double a, b, c;
	myAdd2 ay;

};

double myAdd::addFunc(double m1, double m2)
{
	double m = 0.1*ay.add2(m1) + m2;
	return m;
}

