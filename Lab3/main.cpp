#include "triangle.h"
#include <iostream>
#include <vector>

int main() {
    Point a, b, c;
    std::cout << "Введіть координати трикутника (x1 y1 x2 y2 x3 y3): ";
    std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    Triangle triangle(a, b, c);

    if (triangle.isDegenerate()) {
        std::cout << "Трикутник є виродженим (площа = 0)." << std::endl;
        return 1;
    }

    int numPoints;
    std::cout << "Введіть кількість точок: ";
    std::cin >> numPoints;

    std::vector<Point> points(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Введіть координати точки " << i + 1 << " (x y): ";
        std::cin >> points[i].x >> points[i].y;
    }

    for (const auto& p : points) {
        if (triangle.containsPoint(p)) {
            if (triangle.isOnEdge(p))
                std::cout << "Точка (" << p.x << ", " << p.y << ") лежить на межі трикутника." << std::endl;
            else
                std::cout << "Точка (" << p.x << ", " << p.y << ") всередині трикутника." << std::endl;
        } else {
            std::cout << "Точка (" << p.x << ", " << p.y << ") поза трикутником." << std::endl;
        }
    }

    return 0;
}