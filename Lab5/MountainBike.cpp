#include "MountainBike.h"
#include <iostream>

MountainBike::MountainBike(const std::string& brand, int year, bool hasBell, int gearCount)
    : Bicycle(brand, year, hasBell), gearCount(gearCount) {}

void MountainBike::displayInfo() const {
    Bicycle::displayInfo();
    std::cout << "Mountain Bike with " << gearCount << " gears." << std::endl;
}
