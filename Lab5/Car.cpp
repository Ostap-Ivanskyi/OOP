#include "Car.h"
#include <iostream>

Car::Car(const std::string& brand, int year, int numDoors)
    : Vehicle(brand, year), numDoors(numDoors) {}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Car with " << numDoors << " doors." << std::endl;
}
