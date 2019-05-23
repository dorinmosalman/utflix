#include "Followers.h"

void Followers :: post(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3)
        throw Bad_request();
    if(!(words[2] == "?" && words[3] == "user_id")){
        throw Bad_request();
    }
    int pub_id = stoi(words[4]);
    manager->find_profile(pub_id)->is_publisher();
    Profile* publisher = manager->find_profile(pub_id);
    Profile* loggedin_pro = manager->get_loggedin_pro();
    loggedin_pro->follow(publisher);
    publisher->add_followers(loggedin_pro);
    std :: string msg = "User " + loggedin_pro->get_user() + " with id " + std :: to_string(loggedin_pro->get_id()) + " follow you.";
    publisher->add_notif(msg);
    std :: cout << "OK" << std :: endl;
}

void Followers :: get(Manager* manager, std :: vector<std :: string> words){
    std :: cout << "List of Followers" << std :: endl;
    std :: cout << "#. User Id | User Username | User Email"<< std :: endl;
    manager->get_loggedin_pro()->show_followers();

}