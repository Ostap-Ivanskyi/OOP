#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car {
    int batteryRange;

public:
    ElectricCar(const std::string& brand, int year, int numDoors, int batteryRange);
    void displayInfo() const override;
};

#endif
