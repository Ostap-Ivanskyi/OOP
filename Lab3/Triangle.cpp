#include "triangle.h"
#include <cmath>
#include <iostream>

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double Triangle::area() const {
    double sideA = distance(a, b);
    double sideB = distance(b, c);
    double sideC = distance(c, a);
    double s = (sideA + sideB + sideC) / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

bool Triangle::containsByArea(const Point& p) const {
    Triangle t1 = {a, b, p};
    Triangle t2 = {b, c, p};
    Triangle t3 = {c, a, p};
    double s_main = area();
    double s_sum = t1.area() + t2.area() + t3.area();
    return std::fabs(s_main - s_sum) < 1e-9;
}

double Triangle::crossProduct(const Point& p1, const Point& p2, const Point& p3) const {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool Triangle::isDegenerate() const {
    return std::fabs(crossProduct(a, b, c)) < 1e-9;
}

bool Triangle::containsByCrossProduct(const Point& p) const {
    double cp1 = crossProduct(a, b, p);
    double cp2 = crossProduct(b, c, p);
    double cp3 = crossProduct(c, a, p);

    if (std::fabs(cp1) < 1e-9 || std::fabs(cp2) < 1e-9 || std::fabs(cp3) < 1e-9) {
        return isOnEdge(p);
    }

    bool sameSign = (cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0);
    return sameSign;
}

bool Triangle::isOnEdge(const Point& p) const {
    return std::fabs(crossProduct(a, b, p)) < 1e-9 &&
           ((p.x - a.x) * (p.x - b.x) <= 0) && ((p.y - a.y) * (p.y - b.y) <= 0) ||
           std::fabs(crossProduct(b, c, p)) < 1e-9 &&
           ((p.x - b.x) * (p.x - c.x) <= 0) && ((p.y - b.y) * (p.y - c.y) <= 0) ||
           std::fabs(crossProduct(c, a, p)) < 1e-9 &&
           ((p.x - c.x) * (p.x - a.x) <= 0) && ((p.y - c.y) * (p.y - a.y) <= 0);
}