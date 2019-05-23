#include "Publisher.h"


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
}

void Publisher :: add_followers(Profile* profile){
    followers.push_back(profile);
}

void Publisher :: show_followers(){
    for(int i = 0 ; i < followers.size() ; i++){
        std :: cout << i + 1 << ". ";
        followers[i]->show_profile();
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
void Publisher :: has_published(int film_id){
    for(int i = 0; i < films.size(); i++){
        if(films[i]->get_id() == film_id)
         return;
    }
    throw Bad_permission();
}

void Publisher :: show_published(std :: vector<std :: string> words){
    std :: cout << FILM_HEADER << std :: endl;
    int row =1;
    for(int i = 0; i < films.size(); i++){
        if(films[i]->is_qualified(words)){
            std :: cout << row << ". ";
            films[i]->view_film();
            std :: cout << std :: endl;
            row++;
        }
    }

}