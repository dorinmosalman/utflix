#include "Manager.h"

void Manager :: add_profile(std :: string init_email, std :: string init_username, std :: string init_password, int init_age){
    new_pro_valid(init_username);
    profiles.push_back(new User(init_email, init_username, init_password, init_age, profiles.size()));
    loggedin_profile = profiles[profiles.size() - 1];

}

void Manager :: add_profile(std :: string init_email, std :: string init_username, std :: string init_password, int init_age, bool is_publisher){
    
    new_pro_valid(init_username);   
    if(is_publisher){
        profiles.push_back(new Publisher(init_email, init_username, init_password, init_age, profiles.size()));
    }
    else{
        profiles.push_back(new User(init_email, init_username, init_password, init_age, profiles.size()));
    }
    loggedin_profile = profiles[profiles.size() - 1];
}

Profile* Manager :: find_profile(std :: string user){
    for(int i = 0 ; i < profiles.size() ; i++){
        if(profiles[i]->get_user() == user)
            return profiles[i];
    }
    throw Bad_request();
}

void Manager :: login(std :: string user, std :: string pass){
    
    Profile* profile = find_profile(user);
    profile->login(pass);
    loggedin_profile = profile;
    std :: cout << "OK" << std :: endl;
    
}

void Manager :: new_pro_valid(std :: string user){
    for(int i = 0 ; i < profiles.size() ; i++){
        if(user == profiles[i]->get_user())
            throw Bad_request();
    }
}

void Manager :: add_film(Profile* publisher, std :: string name, int year, int length, int price, std :: string summary, std :: string director){
    Film* new_film = publisher-> add_film(name, year, length, price, summary, director, ++total_films_count);
    total_films.push_back(new_film);
    std :: cout << "OK" << std :: endl;
}


Film* Manager :: find_film(int film_id){
    for(int i = 0 ; i < total_films.size() ; i++){
        if(film_id == total_films[i]->get_id()){
            return total_films[i];
        }
    }
    throw Not_found();
}

int Manager :: get_film_order(int id){
    for(int i = 0 ; i < total_films.size() ; i++){
        if(total_films[i]->get_id() == id)
            return i;
    }
    throw Bad_request();
}

void Manager :: delete_film(int id){
    int order = get_film_order(id);
    delete total_films[order];
    total_films.erase(total_films.begin() + order);

}

Profile* Manager :: find_profile(int id){
    for(int i = 0; i < profiles.size(); i++){
        if(profiles[i]->get_id() == id){
            return profiles[i];
        }
    }
    throw Not_found();
}

void Manager :: buy_film(Film* film){
    accounting->add_money(film);
}

void Manager :: pub_get_money(int pub_id){
    int added_money = accounting->get_pub_money(pub_id);
    Profile* publisher = find_profile(pub_id);
    publisher->get_money(added_money);
    
}

void Manager :: show_film_recoms(){
    std :: cout << std :: endl << "Recommendation Film" << std :: endl << 
    RECOM_HEADER << std :: endl;
    Profile* profile = get_loggedin_pro();
    int max = 11;
    int show;
    bool flag;
    int row = 1;
    for(int i = 0; i < 4; i++){
        int min = 0;
        flag = false;
        for(int j = 0 ; j < total_films.size(); j++){
            if(total_films[j]->get_rate() >= min && total_films[j]->get_rate() < max){
                min = total_films[j]->get_rate();
                if(!profile->film_bought(total_films[j]->get_id())){
                    show = j;
                    flag = true;
                }

            }

            
        }
        if(flag){
            std :: cout << row << ". ";
            total_films[show]->view_for_recoms();
            max = total_films[show]->get_rate();
            row++;
        }
    }
}


Profile* Manager :: get_loggedin_pro(){
    if(loggedin_profile == nullptr){
        throw Bad_permission();
    }
    return loggedin_profile;
}