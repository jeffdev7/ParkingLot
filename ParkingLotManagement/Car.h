#pragma once
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;


class Car
{
private:
	char Code[3];
	char Plate[10];
	char Car[10];
	char FirstName[15];
	char LastName[15];
public:
	void readLot();
	void showLot();
	void writeCar();
	void readCar();
	void searchCar();
	void deleteCar();
};

