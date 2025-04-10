#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

struct Triangle {
    Point a, b, c;

    // Area method functions
    double area() const;
    bool containsByArea(const Point& p) const;

    // Cross product method functions
    double crossProduct(const Point& p1, const Point& p2, const Point& p3) const;
    bool isDegenerate() const;
    bool containsByCrossProduct(const Point& p) const;
    bool isOnEdge(const Point& p) const;
};

double distance(const Point& p1, const Point& p2);


#endif // TRIANGLE_H