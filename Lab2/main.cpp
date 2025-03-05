#include <fstream>
#include <iostream>
#include "Price.h"


int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return 1;
    }

    Price total={0,0};
    int hrn, quantity;
    short int kop;

    std::cout << "FILE" << std::endl;
    while (fscanf(file, "%*[^,], %d %*s %d %*[^,], %d;\n", &hrn, &kop, &quantity) == 3) {
        std::cout << hrn << " hrn " << kop << " kop " << quantity << std::endl;
        Price itemPrice = createPrice(hrn, kop);
        Price totalItemPrice = multiplyPrice(itemPrice, quantity);
        total = addPrices(total, totalItemPrice);
    }

    fclose(file);

    std::cout << "Total: ";
    print(total);

    Price roundedTotal = total;
    round(roundedTotal);

    std::cout << "Rounded: ";
    print(roundedTotal);

    return 0;
}
