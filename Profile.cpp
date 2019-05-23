#include "Profile.h"

bool Profile :: check_password(std :: string pass){
    if(pass == password)
        return true;
    return false;
}

void Profile :: login(std :: string pass){
    if(pass == password)
        login_sit = true;
    else
        throw Bad_request();
}

void Profile :: follow(Profile* publisher){
    followings.push_back(publisher);
}

void Profile :: show_profile(){
    std :: cout << id << SEPARATOR << username << SEPARATOR << email << std :: endl;
}

void Profile :: add_money(int amount){
    money += amount;
}

bool Profile :: film_bought(int film_id){
    for(int i = 0 ; i < bought_films.size() ; i++){
        if(film_id == bought_films[i]->get_id()){
            return true;
        }
    }
    return false;
}

void Profile :: buy_film(Film* film){
    if(film_bought(film->get_id())){
        throw Bad_request();
    }
    int price = film->get_price();
    if(price > money){
        throw Bad_request();
    }
    bought_films.push_back(film);
    money -= price;
}

void Profile :: add_notif(std :: string msg){
    notifications.push_back(new Notification(msg));
}

void Profile :: show_notifs(){
    int row = 1;
    std :: cout << "#. Notification Message" << std :: endl;
    for(int i = notifications.size()-1; i >= 0; --i){
        if(notifications[i]->is_read())
            continue;
        std :: cout << row <<". " << notifications[i]->get_msg() << std :: endl;
        notifications[i]->read();
        row++;
    }
}

void Profile :: show_read_notifs(int limit){
    int row = 1;
    std :: cout << "#. Notification Message" << std :: endl;
    for(int i = notifications.size()-1; i >= 0; i--){
        if(notifications[i]->is_read()){
        std :: cout << row <<". " << notifications[i]->get_msg() << std :: endl;
        if(row == limit)
            return;
        row++;
        }
    }
}

void Profile :: show_purchased_films(std :: vector<std :: string> words){
    int row =1;
    for(int i = 0; i < bought_films.size(); i++){
        if(bought_films[i]->is_qualified(words)){
            std :: cout << row << ". ";
            bought_films[i]->view_for_recoms();
            row++;
        }
    }
}