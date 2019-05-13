#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include <string>

#include "Exceptions.h"

class Profile{
public:
    Profile(std :: string init_email, std :: string init_username, int init_password,int init_age, int init_id)
        : email(init_email), username(init_username), password(init_password), age(init_age), id(init_id), login_sit(true){}
    bool check_password(int pass);
    virtual void view() = 0;
    void login(int pass);
    std :: string get_user(){ return username; }
    
    virtual void add_film(std :: string name, int year, int length, int price, std :: string summary, std :: string director, int id) = 0;

protected:
    
    std :: string email;
    std :: string username;
    int password;
    int age;
    bool login_sit;
    int id;


};

#endif