#include "Buy.h"

void Buy ::  post(Manager* manager, std :: vector<std :: string> words){
    if(!(words[2] == "?" && words[3] == "film_id")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    int film_id = stoi(words[4]);
    Film* film = manager->find_film(film_id);
    Profile* profile = manager->get_loggedin_pro();
    std :: cout << "loggedin pro" << std :: endl;
    profile->buy_film(film);
    manager->buy_film(film);
    Profile* publisher = manager->find_profile(film->get_pub_id());
    std :: string msg = "User " + profile->get_user() + " with id " 
    + std :: to_string(profile->get_id()) + " buy your film " + film->get_name() + " with id " 
    + std :: to_string(film->get_id()) + ".";
    
    publisher->add_notif(msg);


}