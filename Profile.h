#ifndef PROFILE_H
#define PROFILE_H


#include <iostream>
#include <string>

#include "Exceptions.h"
#include "Film.h"
#include "Notification.h"
#include <vector>


class Profile{
public:
    Profile(std :: string init_email, std :: string init_username, std :: string init_password,int init_age, int init_id)
        : email(init_email), username(init_username), password(init_password), age(init_age), id(++init_id), login_sit(true), money(0){}
    bool check_password(std :: string pass);
    void login(std :: string pass);
    std :: string get_user(){ return username; }
    int get_id(){ return id; }
    
    virtual Film* add_film(std :: string name, int year, int length, int price, std :: string summary, std :: string director, int id) = 0;
    virtual Film* find_film(int id) = 0;
    virtual int get_film_order(int id) = 0;
    virtual void delete_film(int id) = 0;
    virtual void is_publisher() = 0;
    virtual void add_followers(Profile* new_profile) = 0;
    virtual void show_followers() = 0;
    virtual void get_money(int added_money) = 0;
    virtual void send_notif_followers(std :: string msg) = 0;
    virtual void has_published(int film_id) = 0;
    virtual std :: vector<Film*> get_films() = 0;
    virtual void show_published(std :: vector<std :: string> words) = 0;

    void show_profile();
    void follow(Profile* publisher);
    void add_money(int amount);
    bool film_bought(int film_id);
    void buy_film(Film* film);
    void add_notif(std :: string msg);
    void show_notifs();
    void show_read_notifs(int limit);
    void show_purchased_films(std :: vector<std :: string> words);


protected:
    
    std :: string email;
    std :: string username;
    std :: string password;
    int age;
    bool login_sit;
    int id;
    std :: vector<Profile*> followings;
    int money;
    std :: vector<Film*> bought_films;
    std :: vector<Notification*> notifications;


};

#endif