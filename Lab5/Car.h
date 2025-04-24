#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
    int numDoors;

public:
    Car(const std::string& brand, int year, int numDoors);
    void displayInfo() const override;
};

#endif
