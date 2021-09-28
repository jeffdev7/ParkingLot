#include "Car.h"
#include <iostream>
#include <cstdlib>
#include<fstream>

//READ all
void Car::readLot() {
	cout << "\n Code: ";
	cin >> Code;
	cout << "\n Plate number: ";
	cin >> Plate;
	cout << "\n Car brand: ";
	cin >> Car;
	cout << "\n First name: ";
	cin >> FirstName;
	cout << "\n Last name: ";
	cin >> LastName;
	cout << endl;
}

//SHOW ALL
void Car::showLot() {
	cout << " Code: " << Code << endl;
	cout << " Plate: " << Plate << endl;
	cout << " Car brand: " << Car << endl;
	cout << " First name: " << FirstName << endl;
	cout << " Last name: " << LastName << endl;
	cout << "================================================================\n" << endl;
}

//WRITE NEW CAR
void Car::writeCar() {
	ofstream outfile;
	outfile.open("car.lot", ios::binary | ios::app);
	readLot();
	outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
	outfile.close();
}

//READ NEW CAR
void Car::readCar() {
	ifstream infile;
	infile.open("car.lot", ios::binary);
	if (!infile) {
		cout << " NOT FOUND!" << endl;
		return;
	}
	cout << "\n************Current menu**********************" << endl;
	while (!infile.eof()) {
		if (infile.read(reinterpret_cast<char*>(this), sizeof(*this))) {
			showLot();
		}
	}
	infile.close();
}

//SEARCH CAR
void Car::searchCar() {
	int n;
	ifstream infile;
	infile.open("car.lot", ios::binary);
	if (!infile) {
		cout << "\n NOT FOUND!" << endl;
		return;
	}
	infile.seekg(0, ios::end);
	int count = infile.tellg() / sizeof(*this);
	cout << "\n Insert the code to search: ";
	cin >> n;
	infile.seekg((n - 1) * sizeof(*this));
	infile.read(reinterpret_cast<char*>(this), sizeof(*this));
	showLot();
}

//DELETE CAR but it's deleting all of it
void Car::deleteCar() {
	int n;
	ifstream infile;
	infile.open("car.lot", ios::binary);
	if (!infile) {
		cout << " NOT FOUND!" << endl;
		return;
	}
	infile.seekg(0, ios::end);
	int count = infile.tellg() / sizeof(*this);
	cout << "\n Insert the code in order to delete: ";
	cin >> n;
	fstream tmpfile;
	tmpfile.open("tpmfile.lot", ios::out | ios::binary);
	infile.seekg(0);
	for (int i = 0; i < count; i++) {
		infile.read(reinterpret_cast<char*>(this), sizeof(*this));
		if (i == (n - 1))
			continue;
		tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
	}
	infile.close();
	tmpfile.close();
	remove("car.lot");
	rename("tmpfile.lot", "menu.lot");
}
