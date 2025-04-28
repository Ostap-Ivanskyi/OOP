#include <iostream>
#include <string>

using namespace std;

// Базовий клас Vehicle
class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(const string& b, int y) : brand(b), year(y) {
        cout << "Vehicle constructor called for " << brand << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor called for " << brand << endl;
    }

    virtual void displayInfo() const {
        cout << "Brand: " << brand << ", Year: " << year;
    }

    string getBrand() const { return brand; }
    int getYear() const { return year; }
};

// Клас Car з віртуальним успадкуванням від Vehicle
class Car : virtual public Vehicle {
protected:
    int numDoors;

public:
    Car(const string& b, int y, int doors) : Vehicle(b, y), numDoors(doors) {
        cout << "Car constructor called for " << brand << endl;
    }

    virtual ~Car() {
        cout << "Car destructor called for " << brand << endl;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << ", Doors: " << numDoors;
    }
};


class Bicycle : virtual public Vehicle {
protected:
    bool hasBell;

public:
    Bicycle(const string& b, int y, bool bell) : Vehicle(b, y), hasBell(bell) {
        cout << "Bicycle constructor called for " << brand << endl;
    }

    virtual ~Bicycle() {
        cout << "Bicycle destructor called for " << brand << endl;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << ", Has bell: " << (hasBell ? "Yes" : "No");
    }
};


class ElectricCar : public Car {
protected:
    int batteryRange;

public:
    ElectricCar(const string& b, int y, int doors, int range)
        : Vehicle(b, y), Car(b, y, doors), batteryRange(range) {
        cout << "ElectricCar constructor called for " << brand << endl;
    }

    ~ElectricCar() override {
        cout << "ElectricCar destructor called for " << brand << endl;
    }

    void displayInfo() const override {
        Car::displayInfo();
        cout << ", Battery range: " << batteryRange << " km";
    }
};


class MountainBike : public Bicycle {
protected:
    int gearCount;

public:
    MountainBike(const string& b, int y, bool bell, int gears)
        : Vehicle(b, y), Bicycle(b, y, bell), gearCount(gears) {
        cout << "MountainBike constructor called for " << brand << endl;
    }

    ~MountainBike() override {
        cout << "MountainBike destructor called for " << brand << endl;
    }

    void displayInfo() const override {
        Bicycle::displayInfo();
        cout << ", Gears: " << gearCount;
    }
};


class HybridVehicle : public Car, public Bicycle, public ElectricCar {
private:
    string hybridType;

public:
    HybridVehicle(const string& b, int y, int doors, bool bell, int range, const string& type)
        : Vehicle(b, y), Car(b, y, doors), Bicycle(b, y, bell),
          ElectricCar(b, y, doors, range), hybridType(type) {
        cout << "HybridVehicle constructor called for " << brand << endl;
    }

    ~HybridVehicle() override {
        cout << "HybridVehicle destructor called for " << brand << endl;
    }

    void displayInfo() const override {
        ElectricCar::displayInfo();
        cout << ", Has bell: " << (hasBell ? "Yes" : "No");
        cout << ", Hybrid type: " << hybridType;
    }
};

int main() {
    cout << "=== Creating ElectricCar ===" << endl;
    ElectricCar tesla("Tesla", 2023, 4, 500);
    tesla.displayInfo();
    cout << endl << endl;

    cout << "=== Creating MountainBike ===" << endl;
    MountainBike bike("Trek", 2022, true, 21);
    bike.displayInfo();
    cout << endl << endl;

    cout << "=== Creating HybridVehicle ===" << endl;
    HybridVehicle hybrid("Toyota", 2024, 4, false, 50, "Plug-in");
    hybrid.displayInfo();
    cout << endl << endl;

    cout << "=== Objects going out of scope ===" << endl;
    return 0;
}