#include "Notifications.h"

void Notifications :: get(Manager* manager){
    manager->get_loggedin_pro()->show_notifs();
}

void Notifications :: get(Manager* manager, std :: vector<std :: string> words){
    if(!(words[2] == "read" && words[3] == "?")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    int i = 4, limit;
    while( i < words.size()){
        if(words[i] == "limit"){
            limit = stoi(words[i+1]);
        }
        i+=2;
    }
    Profile* loggedin_pro = manager->get_loggedin_pro();
    loggedin_pro->show_read_notifs(limit);
}