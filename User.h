#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Profile.h"
#include "Exceptions.h"
#include "Film.h"

class User : public Profile{
public:
    User(std :: string init_email, std :: string init_username, std :: string init_password, int init_age, int init_id)
        : Profile(init_email, init_username, init_password, init_age, init_id){}

    virtual Film* add_film(std :: string name, int year, int length, int price, std :: string summary, std :: string director, int id){ throw Bad_permission(); }
    virtual Film* find_film(int id);
    virtual int get_film_order(int id);
    virtual void delete_film(int id);
    virtual void is_publisher();
    virtual void add_followers(Profile* profile);
    virtual void show_followers();
    virtual void get_money(int added_money);
    virtual void send_notif_followers(std :: string msg);
    virtual void has_published(int film_id);
    virtual std :: vector<Film*> get_films();
    virtual void show_published(std :: vector<std :: string> words);
protected:

};

#endif