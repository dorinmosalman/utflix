#include "Login.h"



void Login :: post(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3)
        throw Bad_request();
    if(!(words[2] == "?"))
        throw Bad_request();

    std :: string username, password;

    int i = 3;
    while (i < words.size()){
        if(words[i] == "username"){
            username = words[i+1];
        }
        if(words[i] == "password"){
            password = words[i+1];
        }
        i+=2;
    }
    manager->login(username, password); 
}
