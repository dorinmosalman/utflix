#include "Comments.h"

void Comments :: post(Manager* manager, std :: vector<std :: string> words){
    if(!(words[2] == "?")){
        throw Bad_request();
    }
    bool film_id_bool = false;
    bool content_bool = false;
    int i = 3, film_id;
    std :: string content;
    while( i < words.size()){
        if(words[i] == "film_id"){
            film_id = stoi(words[i+1]);
            film_id_bool = true;
        }
        else if(words[i] == "content"){
            content = words[i+1];
            content_bool = true;
        }
        i+=2;
    }
    if(!(content_bool && film_id_bool)){
        throw Bad_request();
    }
    Film* film = manager->find_film(film_id);
    int person_id = manager->get_loggedin_pro()->get_id();
    film->add_comment(content, person_id);
    Profile* loggedin_pro = manager->get_loggedin_pro();
    Profile* publisher = manager->find_profile(film->get_pub_id());
    publisher->has_published(film_id);
    std :: string msg;
    msg = "User " + loggedin_pro->get_user() + " with id " + std :: to_string(loggedin_pro->get_id())
    + " comment on your film " + film->get_name() + " with id " + std :: to_string(film->get_id()) +".";
    publisher->add_notif(msg);
    std :: cout << "OK" << std :: endl;
}

void Comments :: delete_(Manager* manager, std :: vector<std :: string> words){
    if(!(words[2]== "?")){
        throw Bad_request();
    }
    int i = 3;
    bool film_id_bool = false;
    bool comment_id_bool = false;
    int film_id, comment_id;
    while( i < words.size()){
        if(words[i] == "film_id"){
            film_id = stoi(words[i+1]);
            film_id_bool = true;
        }
        else if(words[i] == "comment_id"){
            comment_id = stoi(words[i+1]);
            comment_id_bool = true;
        }
        i+=2;
    }
    if(!(comment_id_bool && film_id_bool))
        throw Bad_request();

    Profile* publisher = manager->get_loggedin_pro();
    publisher->has_published(film_id);
    
    Film* film = manager->find_film(film_id);
    film->delete_comment(comment_id);
    std :: cout << "OK" << std :: endl;
    

}