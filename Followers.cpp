#include "Followers.h"

void Followers :: post(Manager* manager, std :: vector<std :: string> words){
    if(!(words[2] == "?" && words[3] == "user_id")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    int pub_id = stoi(words[4]);
    std :: cout << "publisher id = "<< pub_id << std :: endl;
    manager->find_profile(pub_id)->is_publisher();
    std :: cout << "given id is a publisher" << std :: endl;
    Profile* publisher = manager->find_profile(pub_id);
    Profile* loggedin_pro = manager->get_loggedin_pro();
    loggedin_pro->follow(publisher);
    publisher->add_followers(loggedin_pro);
    std :: string msg = "User " + loggedin_pro->get_user() + " with id " + std :: to_string(loggedin_pro->get_id()) + " follow you.";
    publisher->add_notif(msg);
    // manager->get_loggedin_pro()->follow(pub_id);
    // manager->find_profile(pub_id)->add_followers(manager->get_loggedin_pro()->get_id()); //CHANGE
}

void Followers :: get(Manager* manager, std :: vector<std :: string> words){
    std :: cout << "get followers" << std :: endl;
    manager->get_loggedin_pro()->show_followers();

}