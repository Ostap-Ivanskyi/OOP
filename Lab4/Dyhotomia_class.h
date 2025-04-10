#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia_class {
public:
    Dyhotomia_class();

    ~Dyhotomia_class();

    void setVolumes(double vol_a, double vol_b);

    void setTolerance(double vol_eps);

    double solveByBisection(double (*func)(double));

    double solveByNewton(double (*func)(double), double (*derivative)(double), double initialGuess);

private:
    double a;
    double b;
    double eps;
};

#endif // DYHOTOMIA_CLASS_H
