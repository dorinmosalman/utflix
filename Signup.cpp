#include "Signup.h"


void Signup :: post(Manager* manager, std :: vector<std :: string> words){
    if(!(words[2] == "?" && words[3] == "email" && words[5] == "username" && words[7] == "password" 
        && words[9] == "age")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    std :: cout << "signup in manager" << std :: endl;
    
    std :: string email = words[4];
    std :: string username = words[6];
    int password = stoi(words[8]);  //password stringgg!!!!!!!

    mail_valid(email);
    age_valid(words[10]);
    int age = stoi(words[10]);
//    bool pub_sit;
    if(words.size() == 13){
        bool pub_sit;
        if(words[11] != "publisher")
            throw Bad_request();
        else if(words[12] == "true"){
            pub_sit = true;
            std :: cout << "publisher situation is true" << std :: endl;
        }
        else{
            pub_sit = false;
            std :: cout << "publisher situation is false" << std :: endl;
        }
        std :: cout << "add profile" << std :: endl;
        manager->add_profile(email, username, password, age, pub_sit);
    }
    else{
        std :: cout << "add profile" << std :: endl;
        manager->add_profile(email, username, password, age);
    }

}



void Signup :: mail_valid(std :: string mail){
    const std :: regex pattern 
    ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if(!std :: regex_match(mail, pattern))
        throw Bad_request();
}

void Signup :: age_valid(std :: string age){
    for(int i = 0; i < age.length(); i++){
        if(age[i] > 57 || age[i] < 48){
            throw Bad_request();
        }
    }
}