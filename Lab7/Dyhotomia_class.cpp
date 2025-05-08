#include "Dyhotomia_class.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Dyhotomia_class::Dyhotomia_class() {
};

Dyhotomia_class::~Dyhotomia_class() {
};

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Dyhotomia_class::solveByBisection(std::function<double(double)> func) {
    if (func(a) * func(b) >= 0) {
        throw std::invalid_argument("Function has the same signs at a and b, or no root in interval.");
    }

    double c;
    while ((b - a) >= eps) {
        c = (a + b) / 2;
        if (func(c) == 0.0) {
            return c;
        } else if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return (a + b) / 2;
}

double Dyhotomia_class::solveByNewton(std::function<double(double)> func, std::function<double(double)> derivative, double initialGuess) {
    double x = initialGuess;
    double h;
    for (int i = 0; i < 100; i++) {
        h = func(x) / derivative(x);
        if (std::abs(h) < eps) {
            break;
        }
        x = x - h;
    }

    return x;
}