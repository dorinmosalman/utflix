#include "Rate.h"

void Rate :: post(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3)
        throw Bad_request();
    if(!(words[2] == "?")){
        throw Bad_request();
    }
    int i = 3;
    int film_id, score;
    bool id_bool = false;
    bool rate_bool = false;
    while( i < words.size()){
        if(words[i] == "film_id"){
            film_id = stoi(words[i+1]);
            id_bool = true;
        }
        else if(words[i] == "score"){
            score = stoi(words[i+1]);
            rate_bool = true;
        }
        i+=2;
    }
    if(!(rate_bool && id_bool)){
        throw Bad_request();
    }
    Profile* loggedin_pro = manager->get_loggedin_pro();
    Film* film = manager->find_film(film_id);
    if(!(loggedin_pro->film_bought(film_id))){
        throw Bad_permission();
    }
    film->score(score, loggedin_pro->get_id());
    std :: string msg;
    Profile* publisher = manager->find_profile(film->get_pub_id());
    msg = "User " + loggedin_pro->get_user() + " with id " + std :: to_string(loggedin_pro->get_id()) 
    + " rate your film " + film->get_name() + "with id " + std :: to_string(film->get_id()) + ".";
    publisher->add_notif(msg);
    std :: cout << "OK" << std :: endl;
}