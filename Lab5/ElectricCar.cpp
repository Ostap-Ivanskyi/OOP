#include "ElectricCar.h"
#include <iostream>

ElectricCar::ElectricCar(const std::string& brand, int year, int numDoors, int batteryRange)
    : Car(brand, year, numDoors), batteryRange(batteryRange) {}

void ElectricCar::displayInfo() const {
    Car::displayInfo();
    std::cout << "Electric range: " << batteryRange << " km." << std::endl;
}
