#include "Publisher.h"

void Publisher :: view(){
    std :: cout << "Publisher with username:\t" << username << std :: endl;
}

void Publisher :: add_film(std :: string name, int year, int length, int price, std :: string summary, std :: string director, int id){
    films.push_back(new Film(name, year, length, price, summary, director, id));
}