#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <iostream>
#include <vector>
#include <map>
#include "Film.h"

class Accounting{
public:
    Accounting();
    void add_money(Film* film);
    int get_total_money(){ return netflix_money; }
    int get_pub_money(int pub_id);


private:
    std :: map<int, int> publisher_money;
    int netflix_money;
    bool publisher_exists(int pub_id);
    int calculate_money(Film* film);
};

#endif