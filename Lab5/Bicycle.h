#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
    bool hasBell;

public:
    Bicycle(const std::string& brand, int year, bool hasBell);
    void displayInfo() const override;
};

#endif
