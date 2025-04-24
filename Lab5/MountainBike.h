#ifndef MOUNTAINBIKE_H
#define MOUNTAINBIKE_H

#include "Bicycle.h"

class MountainBike : public Bicycle {
    int gearCount;

public:
    MountainBike(const std::string& brand, int year, bool hasBell, int gearCount);
    void displayInfo() const override;
};

#endif
