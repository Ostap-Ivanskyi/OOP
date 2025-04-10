#include <iostream>
#include <cmath>
#include "Dyhotomia_class.h"

double func(double x) {
    return 3 * x - 4 * log(x) - 5;
}

double derivative(double x) {
    return 3 - 4 / x;
}

int main() {
    Dyhotomia_class solver;

    solver.setVolumes(2.0, 4.0);
    solver.setTolerance(1e-6);

    try {
        double root_bisection = solver.solveByBisection(func);
        std::cout << "Root found by bisection method: " << root_bisection << std::endl;

        double root_newton = solver.solveByNewton(func, derivative, 3.0);
        std::cout << "Root found by Newton's method: " << root_newton << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
