#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>

#include "Profile.h"
#include "User.h"
#include "Publisher.h"
#include "Exceptions.h"
#include "Film.h"
#include "Accounting.h"


#define FILM_HEADER "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director"
#define RECOM_HEADER "#. Film Id | Film Name | Film Length | Film Director"


class Manager{
public:
    Manager(): total_films_count(0){ accounting = new Accounting(); loggedin_profile = nullptr; }

    void add_profile(std :: string init_email, std :: string init_username, std :: string init_password, int init_age, bool publiher);
    void add_profile(std :: string init_email, std :: string init_username, std :: string init_password, int init_age);
    void login(std :: string user, std :: string pass);
    void new_pro_valid(std :: string user);
    Profile* find_profile(std :: string user);
    Profile* find_profile(int id);
    Profile* get_loggedin_pro();
    void pub_get_money(int pub_id);
    void add_film(Profile* publisher, std :: string name, int year, int length, int price, std :: string summary, std :: string director);
    Film* find_film(int film_id);
    int get_film_order(int id);
    void delete_film(int id);
    void show_film_recoms();
    
    void buy_film(Film* film);
    std :: vector <Film*> get_total_films(){ return total_films; } 
    int total_money(){ return accounting->get_total_money(); }

protected:
    std :: vector<Profile*> profiles;
    std :: vector<Film*> total_films;
    Profile* loggedin_profile;
    int total_films_count;
    Accounting* accounting;
};

#endif