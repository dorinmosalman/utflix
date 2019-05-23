#include "User.h"


Film* User :: find_film(int id){
    throw Bad_permission();
}

int User :: get_film_order(int id){
    throw Bad_permission();
}

void User :: delete_film(int id){
    throw Bad_permission();
}

void User :: is_publisher(){
    throw Bad_permission();
}

void User :: add_followers(Profile* profile) {
    throw Bad_request();
}

void User :: show_followers(){
    throw Bad_request();
}

void User :: get_money(int added_money){
    throw Bad_request();
}

void User :: send_notif_followers(std :: string msg){
    throw Bad_request();
}

void User :: has_published(int film_id){
    throw Bad_permission();
}

std :: vector<Film*> User ::  get_films(){
    throw Bad_request();
}

void User :: show_published(std :: vector<std :: string> words){
    throw Bad_permission();
}