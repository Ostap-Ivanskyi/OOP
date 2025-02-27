#include "Price.h"
#include <iostream>
#include <ostream>

Price::Price(int h, short int k) : hrn(h), kop(k) {
}

Price Price::plus(const Price &second) const {
    int totalHrn = hrn + second.hrn;
    short int totalKop = kop + second.kop;

    if (totalKop >= 100) {
        totalHrn += totalKop / 100;
        totalKop %= 100;
    }
    return Price(totalHrn, totalKop);
}

Price Price::mult(int m) const {
    int totalHrn = hrn * m;
    short int totalKop = kop * m;
    if (totalKop >= 100) {
        totalHrn += totalKop / 100;
        totalKop %= 100;
    }
    return Price(totalHrn, totalKop);
}

void Price::round() {
    int rem = kop % 10;
    if (rem >= 5) {
        kop = kop * 10 - rem;
    } else {
        kop -= rem;
    }

    if (kop >= 100) {
        hrn += kop / 100;
        kop %= 100;
    }
}

void Price::print() const {
    std::cout << hrn << "hrn. " << kop << "kop. " << std::endl;
}
