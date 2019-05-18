#include "Profile.h"

bool Profile :: check_password(int pass){
    if(pass == password)
        return true;
    return false;
}

void Profile :: login(int pass){
    if(pass == password)
        login_sit = true;
    else
        throw Bad_request();
}

void Profile :: follow(Profile* publisher){
    followings.push_back(publisher);
}

void Profile :: show_profile(){
    std :: cout << "\t" << id << "\t" << SEPARATOR << "\t" << username << "\t" << SEPARATOR <<"\t"<< email << std :: endl;
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
        std :: cout << "film bought" << std :: endl;
        throw Bad_request();
    }
    int price = film->get_price();
    if(price > money){
        throw Bad_request();
    }
    bought_films.push_back(film);
    money -= price;
    std :: cout << "push back in profile done" << std :: endl;
}

void Profile :: add_notif(std :: string msg){
    notifications.push_back(new Notification(msg));
}

void Profile :: show_notifs(){
    int row = 1;
    std :: cout << "#. Notification Message" << std :: endl;
    for(int i = notifications.size()-1; i >= 0; i--){
        if(notifications[i]->is_read())
            continue;
        std :: cout << row <<". " << notifications[i]->get_msg() << std :: endl;
        notifications[i]->read();
        row++;
    }
}

void Profile :: show_read_notifs(int limit){
    std :: cout << "limit" << limit << std :: endl;
    int row = 1;
    std :: cout << "#. Notification Message" << std :: endl;
    for(int i = notifications.size()-1; i >= 0; i--){
        if(notifications[i]->is_read()){
        std :: cout << row <<". " << notifications[i]->get_msg() << std :: endl;
        // notifications[i]->read();
        if(row == limit)
            return;
        row++;
        }
    }
}