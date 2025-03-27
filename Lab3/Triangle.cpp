#include "triangle.h"
#include <cmath>

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}

double Triangle::crossProduct(const Point& p1, const Point& p2, const Point& p3) const {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool Triangle::isDegenerate() const {
    return std::fabs(crossProduct(a, b, c)) < 1e-9; // Перевірка на площу трикутника (майже нуль)
}

bool Triangle::containsPoint(const Point& p) const {
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
