#include "Films.h"

void Films :: post(Manager* manager, std :: vector<std :: string> words){
        // for(int i = 0 ; i < words.size() ; i++){
    //     std :: cout << words[i] << "." << std :: endl;
    // }
    if(!(words[2] == "?" && words[3] == "name" && words[5] == "year" && words[7] == "length" &&
        words[9] == "price" && words[11] == "summary" && words[13] == "director")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request(); 
    }
    std :: string name = words[4];
    int year = stoi(words[6]);
    int length = stoi(words[8]);
    int price = stoi(words[10]);
    std :: string summary = words[12];
    std :: string director = words[14];

    std :: cout << "1" << std :: endl;
    Profile* loggedin_pro = manager->get_loggedin_pro();
    std :: cout << "2" << std :: endl;
    manager->add_film(loggedin_pro, name, year, length, price, summary, director);
    std :: string msg;
    msg = "Publisher " + loggedin_pro->get_user() + " with id " + std :: to_string(loggedin_pro->get_id()) + " register new film.";
    loggedin_pro->send_notif_followers(msg);
}

void Films :: put(Manager* manager, std :: vector<std :: string> words){
        std :: cout << "edit" << std :: endl;
    if(words[3] != "film_id"){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    int film_id = stoi(words[4]);
    std :: cout << "words4= " << words[4] << "\t film_id= " << film_id << std :: endl;
    Film* film = manager->find_film(film_id);
    int i = 5;
    std :: cout << "words size : " << words.size() << std :: endl;
    while( i < words.size()){
        if(words[i] == "name"){
            film->change_name(words[i + 1]);
            std :: cout << "name changed" << std :: endl;
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
}

void Films :: delete_(Manager* manager,  std :: vector<std :: string> words){
    if(!(words[2] == "?" && words[3] == "film_id")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    int film_id = stoi(words[4]);
    Film* film_in_total = manager->find_film(film_id);
    Film* film_in_pro = manager->get_loggedin_pro()->find_film(film_id);
    
    manager->delete_film(film_id);
    manager->get_loggedin_pro()->delete_film(film_id);

}

void Films :: get(Manager* manager, std :: vector<std :: string> words){
    if(!(words[2] == "?" && words[3] == "film_id")){
        std :: cout << "sabet ha" << std :: endl;
    }
    int film_id = stoi(words[4]);
    Film* film = manager->find_film(film_id);
    film->show_film();
}