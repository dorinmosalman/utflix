#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>

#include "Profile.h"
#include "User.h"
#include "Publisher.h"
#include "Exceptions.h"
#include "Film.h"

class Manager{
public:
    Manager(): total_films(0){ std :: cout << "Manager constructor successful" << std :: endl; }

    void add_profile(std :: string init_email, std :: string init_username, int init_password, int init_age, bool publiher);
    void add_profile(std :: string init_email, std :: string init_username, int init_password, int init_age);
    void view_profiles();
    void login(std :: string user, int pass);
    void new_pro_valid(std :: string user);
    Profile* find_profile(std :: string user);
    Profile* get_loggedin_pro(){ return loggedin_profile; }

    void add_film(Profile* publisher, std :: string name, int year, int length, int price, std :: string summary, std :: string director);

protected:
    std :: vector<Profile*> profiles;
    Profile* loggedin_profile;
    int total_films;
};

#endif