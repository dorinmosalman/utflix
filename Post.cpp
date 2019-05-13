#include "Post.h"

void Post :: handle_command (Manager* manager){

    if(words[2] == "signup"){
        signup(words, manager);
    }
    else if(words[2] == "login"){
        login(words, manager);
    }
    else{
        throw Bad_request();
    }
}

void Post :: signup(std :: vector<std :: string> words, Manager* manager){
    if(!(words[2] == "?" && words[3] == "email" && words[5] == "username" && words[7] == "password" 
        && words[9] == "age"))
        throw Bad_request();
    
    std :: string email = words[4];
    std :: string username = words[6];
    int password = string_to_int(words[8]);
    int age = string_to_int(words[10]);
    bool pub_sit;
    if(words.size() == 12){
        bool pub_sit;
        if(words[11] != "publisher")
            throw Bad_request();
        if(words[12] == "true")
            pub_sit = true;
        else
            pub_sit = false;
        manager->add_profile(email, username, password, age, pub_sit);
    }
    else
        manager->add_profile(email, username, password, age);
}

void Post :: login (std :: vector<std :: string> words, Manager* manager){
    if(!(words[2] == "?" && words[3] == "username" && words[5] == "password"))
        throw Bad_request();
    std :: string username = words[4];
    int password = string_to_int (words[6]);
    manager->login(username, password); 
}