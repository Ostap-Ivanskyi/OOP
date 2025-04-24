#include <iostream>
#include "ElectricCar.h"
#include "MountainBike.h"

int main() {
    ElectricCar tesla("Tesla", 2022, 4, 450);
    MountainBike trek("Trek", 2020, true, 21);

    tesla.displayInfo();
    std::cout << "------------------" << std::endl;
    trek.displayInfo();

    return 0;
}
