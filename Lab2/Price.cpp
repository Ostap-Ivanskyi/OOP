#include "Price.h"
#include <iostream>
#include <ostream>

Price createPrice(int hrn, short kop) {
    Price price;
    price.hrn = hrn;
    price.kop = kop;
    normalizePrice(price);
    return price;
}
void normalizePrice(Price& price) {
    if (price.kop >= 100) {
        price.hrn += price.kop / 100;
        price.kop %= 100;
    }
}

Price addPrices(const Price& a, const Price& b) {
    return createPrice(a.hrn + b.hrn, a.kop + b.kop);
}

Price multiplyPrice(const Price& price, int quantity) {
    return createPrice(price.hrn * quantity, price.kop * quantity);
}

void round( Price& price) {
    int rem = price.kop % 10;
    if (rem >= 5) {
        price.kop = price.kop + 10 - rem;
    } else {
        price.kop -= rem;
    }
    normalizePrice(price);
}

void print(const Price &price) {
    std::cout << price.hrn << " hrn " << price.kop << " kop"<<"\n";
}

