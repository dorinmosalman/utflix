#include "Login.h"



void Login :: post(Manager* manager, std :: vector<std :: string> words){
    if(!(words[2] == "?" && words[3] == "username" && words[5] == "password")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    std :: string username = words[4];
    int password = stoi (words[6]);
    manager->login(username, password); 
}
