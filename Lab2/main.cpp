#include <fstream>
#include <iostream>
#include "Price.h"


int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }

    Price totalSum;
    int hrn, quantity;
    short int kop;

    std::cout << "FILE" << std::endl;
    while (inputFile >> hrn >> kop >> quantity) {
        std::cout << hrn << " hrn " << kop << " kop " << quantity << std::endl;
        Price price(hrn, kop);
        Price productTotal = price.mult(quantity);
        totalSum = totalSum.plus(productTotal);
    }

    inputFile.close();

    std::cout << "Total: ";
    totalSum.print();

    Price roundedTotal = totalSum;
    roundedTotal.round();

    std::cout << "Rounded: ";
    roundedTotal.print();

    return 0;
}
