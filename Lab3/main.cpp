#include "triangle.h"
#include <iostream>
#include <vector>

int main() {
    Triangle triangle;
    std::cout << "Введіть координати трикутника (x1 y1 x2 y2 x3 y3): ";
    std::cin >> triangle.a.x >> triangle.a.y
             >> triangle.b.x >> triangle.b.y
             >> triangle.c.x >> triangle.c.y;

    if (triangle.isDegenerate()) {
        std::cout << "Трикутник є виродженим (площа = 0)." << std::endl;
        return 1;
    }

    int numPoints;
    std::cout << "Введіть кількість точок для перевірки: ";
    std::cin >> numPoints;

    std::vector<Point> points(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        std::cout << "Введіть координати точки " << i + 1 << " (x y): ";
        std::cin >> points[i].x >> points[i].y;
    }

    std::cout << "\nРезультати перевірки:\n";
    for (const auto& p : points) {
        bool onEdge = triangle.isOnEdge(p);
        bool insideArea = triangle.containsByArea(p);
        bool insideCross = triangle.containsByCrossProduct(p);

        std::cout << "Точка (" << p.x << ", " << p.y << "):\n";
        std::cout << "  Метод за площею Герона: " << (insideArea ? "всередині" : "зовні") << "\n";
        std::cout << "  Метод векторного добутку: " << (insideCross ? "всередині" : "зовні") << "\n";

        if (onEdge) {
            std::cout << "  Лежить на межі трикутника\n";
        }
        std::cout << std::endl;
    }

    return 0;
}