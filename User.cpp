#include "User.h"

void User :: view(){
    std :: cout << "User with username: " << username << "and id: " << id << " and money= " << money << " and notifications= " << notifications.size() <<  std :: endl;
}

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
    std :: cout << "id " << id << "is not a publisher" << std :: endl;
    throw Bad_request();
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