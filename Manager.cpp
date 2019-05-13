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
    publisher-> add_film(name, year, length, price, summary, director, ++total_films);
    std :: cout << "OK" << std :: endl;
}