#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <iostream>
#include <string>
#include <vector>

#include "Profile.h"
#include "Film.h"

class Publisher : public Profile{
public:
    Publisher(std :: string init_email, std :: string init_username, int init_password, int init_age, int init_id)
        : Profile(init_email, init_username, init_password, init_age, init_id){}
    virtual void view();

    virtual void add_film(std :: string name, int year, int length, int price, std :: string summary, std :: string director, int id);

protected:
    std :: vector<Film*> films;

};

#endif