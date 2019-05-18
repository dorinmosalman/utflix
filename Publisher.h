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

    virtual Film* add_film(std :: string name, int year, int length, int price, std :: string summary, std :: string director, int id);
    virtual Film* find_film(int id);
    virtual int get_film_order(int id);
    virtual void delete_film(int id);
    virtual void is_publisher();
    virtual void add_followers(Profile* profile);
    virtual void show_followers();
    virtual void get_money(int added_money);
    virtual void send_notif_followers(std :: string msg);

protected:
    std :: vector<Film*> films;
    std :: vector<Profile*> followers;

};

#endif