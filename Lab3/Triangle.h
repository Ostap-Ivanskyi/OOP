#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

class Triangle {
public:
    Triangle(const Point& a, const Point& b, const Point& c);
    bool isDegenerate() const;
    bool containsPoint(const Point& p) const;
    bool isOnEdge(const Point& p) const;
    double crossProduct(const Point& p1, const Point& p2, const Point& p3) const;

private:
    Point a, b, c
};

#endif // TRIANGLE_H
