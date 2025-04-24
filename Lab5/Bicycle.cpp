#include "Bicycle.h"
#include <iostream>

Bicycle::Bicycle(const std::string& brand, int year, bool hasBell)
    : Vehicle(brand, year), hasBell(hasBell) {}

void Bicycle::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Bicycle with bell: " << (hasBell ? "Yes" : "No") << std::endl;
}
