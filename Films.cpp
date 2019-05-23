#include "Films.h"

void Films :: post(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3){
        throw Bad_request();
    }
    else if(words[2] != "?"){
        throw Bad_request();
    }
    std :: string name , summary, director;
    int year, length, price;
    bool name_bool = false;
    bool year_bool = false;
    bool length_bool = false;
    bool price_bool = false;
    bool summary_bool = false;
    bool director_bool = false;

    int i = 3; 
    while(i < words.size()){
        if(words[i] == "name"){
            name = words[i+1];
            name_bool = true;
        }
        else if(words[i] == "year"){
            year = stoi(words[i+1]);
            year_bool = true;
        }
        else if(words[i] == "length"){
            length = stoi(words[i+1]);
            length_bool = true;
        }
        else if(words[i] == "price"){
            price = stoi(words[i+1]);
            price_bool = true;
        }
        else if(words[i] == "summary"){
            summary = words[i+1];
            summary_bool = true;
        }
        else if(words[i] == "director"){
            director = words[i+1];
            director_bool = true;
        }
        i += 2;
    }
    if(!(name_bool && year_bool && length_bool && summary_bool && director_bool)){
        throw Bad_request();
    }

    Profile* loggedin_pro = manager->get_loggedin_pro();
    manager->add_film(loggedin_pro, name, year, length, price, summary, director);
    std :: string msg;
    msg = "Publisher " + loggedin_pro->get_user() + " with id " + std :: to_string(loggedin_pro->get_id()) + " register new film.";
    loggedin_pro->send_notif_followers(msg);
}

void Films :: put(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3)
        throw Bad_request();
    if(words[2] != "?"){
        throw Bad_request();
    }

    int film_id;
    bool film_id_bool = false;
    for(int i = 3; i < words.size(); i+=2){
        if(words[i] == "film_id"){
            film_id = stoi(words[i+1]);
            film_id_bool = true;
        }
    }
    if(!film_id_bool){
        throw Bad_request();
    }
    Film* film = manager->find_film(film_id);
    int i = 5;
    while( i < words.size()){
        if(words[i] == "name"){
            film->change_name(words[i + 1]);
        }
        else if(words[i] == "year"){
            film->change_year(stoi(words[i + 1]));
        }
        else if(words[i] == "length"){
            film->change_length(stoi(words[i + 1]));
        }
        else if(words[i] == "summary"){
            film-> change_summary(words[i + 1]);
        }
        else if(words[i] == "director"){
            film->change_director(words[i + 1]);
        }
        i+=2;
    }
    std :: cout << "OK" << std :: endl;
}

void Films :: delete_(Manager* manager,  std :: vector<std :: string> words){
    if(words.size() < 3){
        throw Bad_request();
    }
    if(!(words[2] == "?")){
        throw Bad_request();
    }

    int i = 3;
    int film_id;
    bool film_id_given = false;
    while(i < words.size()){
        if(words[i] == "film_id"){
            film_id = stoi(words[i+1]);
            film_id_given = true;
        }
        i+=2;
    }
    if(!film_id_given){
        throw Bad_request();
    }
    Film* film_in_total = manager->find_film(film_id);
    Film* film_in_pro = manager->get_loggedin_pro()->find_film(film_id);
    
    manager->delete_film(film_id);
    manager->get_loggedin_pro()->delete_film(film_id);
    std :: cout << "OK" << std :: endl;

}

void Films :: get_total(Manager* manager, std :: vector<std :: string> words){

    std :: cout << FILM_HEADER << std :: endl;

    std :: vector<Film*> total_films = manager->get_total_films();
    int row = 1;
    for(int i = 0; i < total_films.size(); i++){
        if(total_films[i]->is_qualified(words)){
            std :: cout << row << ". ";
            total_films[i]->view_film();
            std :: cout << std :: endl;
            row++;
        }
    }

}

void Films :: get_with_id(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3)
        throw Bad_request();
    if(!(words[2] == "?" && words[3] == "film_id"))
        throw Bad_request();
    
    int film_id = stoi(words[4]);
    manager->find_film(film_id)->show_film();
    manager->show_film_recoms();
    
}


void Films :: get(Manager* manager, std :: vector<std :: string> words){
    int i = 3;
    while(i < words.size()){
        if(words[i] == "film_id"){
            get_with_id(manager, words);
            return;
        }
        i+=2;
    }
    get_total(manager, words);
}