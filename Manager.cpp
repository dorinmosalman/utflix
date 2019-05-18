#include "Manager.h"

void Manager :: add_profile(std :: string init_email, std :: string init_username, int init_password, int init_age){
    try{
    new_pro_valid(init_username);
    profiles.push_back(new User(init_email, init_username, init_password, init_age, profiles.size()));
    std :: cout << "user made" << std :: endl;
    std :: cout << "OK" << std :: endl;
    loggedin_profile = profiles[profiles.size() - 1];

    }catch(Bad_request ex){
        std :: cout << ex.what() << std :: endl;
    }
}

void Manager :: add_profile(std :: string init_email, std :: string init_username, int init_password, int init_age, bool is_publisher){
    std :: cout << "**";
    try{
        new_pro_valid(init_username);   
    std :: cout << "profile valid" << std :: endl;
    if(is_publisher){
        profiles.push_back(new Publisher(init_email, init_username, init_password, init_age, profiles.size()));
        std :: cout << "Publisher made" << std :: endl;
    }
    else{
        profiles.push_back(new User(init_email, init_username, init_password, init_age, profiles.size()));
        std :: cout << "user made" << std :: endl;
    }
    std :: cout << "OK" << std :: endl;
    loggedin_profile = profiles[profiles.size() - 1];

    }catch(Bad_request ex){
        std :: cout << ex.what() << std :: endl;
    }
}

void Manager :: view_profiles(){
    for(int i = 0 ; i < profiles.size() ; i++){
        profiles[i]->view();
    }
}

Profile* Manager :: find_profile(std :: string user){
    for(int i = 0 ; i < profiles.size() ; i++){
        if(profiles[i]->get_user() == user)
            return profiles[i];
    }
    throw Bad_request();
}

void Manager :: login(std :: string user, int pass){
    try{
        Profile* profile = find_profile(user);
        profile->login(pass);
        loggedin_profile = profile;
        std :: cout << "OK" << std :: endl;
        std :: cout << "login okay" << std :: endl;
    } catch (Bad_request ex){
        std :: cout << ex.what() << std :: endl;
    }
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
        std :: cout << "i= " << i << "\t id= " << total_films[i]->get_id() << "\t film_id= " << film_id<< std :: endl;
        if(film_id == total_films[i]->get_id()){
            std :: cout << "found film" << std :: endl;
            return total_films[i];
        }
    }
    std :: cout << "film not found" << std :: endl;
    throw Bad_request();
}

void Manager :: view_films(){
    for(int i = 0; i < total_films.size(); i++){
        std :: cout << "film id: " << total_films[i]-> get_id() << std :: endl;
        std :: cout << "film_name: " << total_films[i]->get_name() << std :: endl;
        std :: cout << "film rate: " << total_films[i]->get_rate() << std :: endl;
    }
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
    throw Bad_request();
}

void Manager :: buy_film(Film* film){
    std :: cout << "manager buy film" << std :: endl;
    accounting->add_money(film);
}

void Manager :: pub_get_money(int pub_id){
    int added_money = accounting->get_pub_money(pub_id);
    Profile* publisher = find_profile(pub_id);
    publisher->get_money(added_money);
    
}