
#ifndef PRICE_H
#define PRICE_H

struct Price {
    int hrn;
    short int kop;

    Price(int hrn=0, short kop=0);

    Price plus (const Price& second) const;
    Price mult (int m)const;

    void round();
    void print()const;
};

#endif //PRICE_H
