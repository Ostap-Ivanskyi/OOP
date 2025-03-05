
#ifndef PRICE_H
#define PRICE_H

struct Price {
    int hrn;
    short int kop;
};

Price createPrice(int hrn, short kop);
void normalizePrice(Price &price);
Price addPrices (const Price& a,const Price& b);
Price multiplyPrice (const Price& price,int m);

void round(Price& price);
void print(const Price& price);

#endif //PRICE_H
