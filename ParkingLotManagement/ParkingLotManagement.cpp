#include <iostream>
#include "Car.h"
#include <fstream>
#include <cstdlib>

int main()
{
    Car car;
    int choice;
    cout << "******Parking lot Management*********" << endl;
    while (true) {
        cout << "\n Select one of the options below ";
        cout << "\n 1--> Add a new car ";
        cout << "\n 2--> Show menu ";
        cout << "\n 3--> Search a car ";
        cout << "\n 4--> Delete a car ";
        cout << "\n 5--> Quit ";
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: car.writeCar();
            break;
        case 2: car.readCar();
            break;
        case 3: 
            car.searchCar();
            break;
        case 4: car.deleteCar();
            break;
        case 5: exit(0);
            break;
        default:
            cout << "\n Enter the correct choice please!";
            exit(0);
        }
    }
    system("pause");
    return 0;
}

