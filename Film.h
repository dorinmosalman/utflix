#ifndef FILM_H
#define FILM_H

#include <iostream>

class Film{
public:
    Film(std :: string init_name, int init_year, int init_length, int init_price,
    std :: string init_summary, std :: string init_director, int init_id)
        : name(init_name), year(init_year), length(init_length), 
        price(init_price), summery(init_summary), director(init_director), id(init_id){}

private:
    std :: string name;
    int year;
    int length;
    int price;
    int id;
    std :: string summery;
    std :: string director;
};

#endif