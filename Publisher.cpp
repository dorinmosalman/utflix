#include "Publisher.h"

void Publisher :: view(){
    std :: cout << "Publisher with username: " << username << "and id: " << id << " and money= " << money << " and notifications= " << notifications.size() << std :: endl;
}

Film* Publisher :: add_film(std :: string name, int year, int length, int price, std :: string summary, std :: string director, int film_id){
    films.push_back(new Film(name, year, length, price, summary, director, film_id, id));
    return films[films.size() - 1];
}

Film* Publisher :: find_film(int id){
    for(int i = 0 ; i < films.size() ; i++){
        if(films[i]->get_id() == id){
            return films[i];
        }
    }    bool publisher_exists(int pub_id);
    int calculate_money(Film* film);
    throw Bad_permission();
}

int Publisher :: get_film_order(int id){
    for(int i = 0 ; i < films.size() ; i++){
        if(films[i]->get_id() == id)
            return i;
    }
    throw Bad_permission();
}

void Publisher :: delete_film(int id){
    int order;
    for(int i = 0 ; i < films.size() ; i++){
        if(films[i]->get_id() == id){
            order = i;
        }
    }
    films.erase(films.begin() + order);
}

void Publisher :: is_publisher(){
    std :: cout <<"id " << id << "is a publisher" << std :: endl;
}

void Publisher :: add_followers(Profile* profile){
    followers.push_back(profile);
}

void Publisher :: show_followers(){
    std :: cout << "#. User Id  |  User Username  | User Email" << std :: endl;
    for(int i = 0 ; i < followers.size() ; i++){
        std :: cout << i + 1 << ". ";
        followers[i]->show_profile();
        std :: cout << std :: endl;
    }
}

void Publisher :: get_money(int added_money){
    money += added_money;
}

void Publisher :: send_notif_followers(std :: string msg){
    for(int i = 0 ; i < followers.size() ; i++){
        followers[i]->add_notif(msg);
    }
}