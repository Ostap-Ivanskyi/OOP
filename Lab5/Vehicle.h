#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
    std::string brand;
    int year;

public:
    Vehicle(const std::string& brand, int year);
    virtual ~Vehicle() = default;

    virtual void displayInfo() const;

    std::string getBrand() const;
    int getYear() const;

    void setBrand(const std::string& brand);
    void setYear(int year);
};

#endif
