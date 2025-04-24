#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string& brand, int year) : brand(brand), year(year) {}

void Vehicle::displayInfo() const {
    std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
}

std::string Vehicle::getBrand() const {
    return brand;
}

int Vehicle::getYear() const {
    return year;
}

void Vehicle::setBrand(const std::string& brand) {
    this->brand = brand;
}

void Vehicle::setYear(int year) {
    this->year = year;
}
