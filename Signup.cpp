#include "Signup.h"


void Signup :: post(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3)
        throw Bad_request();
    if(words[2] != "?" || words.size() < 3){
        throw Bad_request();
    }
    
    int i =3;
    std :: string email , username , agest , password;

    bool mail_given = false;
    bool user_given = false;
    bool password_given = false;
    bool age_given = false;
    bool pub_given = false;
    bool pub_sit;
    while(i < words.size()){
        if(words[i] == "email"){
            email = words[i+1];
            mail_given = true;
        }
        else if(words[i] == "username"){
            username = words[i+1];
            user_given = true;
        }
        else if(words[i] == "password"){
            password = words[i+1];
            password_given = true;
        }
        else if(words[i] == "age"){
            agest = words[i+1];
            age_given = true;
        }
        else if(words[i] == "publisher"){
            pub_given = true;
            if(words[i+1] == "true"){
                pub_sit = true;
            }   
            else if(words[i+1] == "false"){
                pub_sit = false;
            }
        }
        
        i+=2;
    }
    mail_valid(email);
    age_valid(agest);
    int age = stoi(agest);

    if(!(mail_given && user_given && password_given && age_given)){
        throw Bad_request();
    }

    if(pub_given){
        manager->add_profile(email, username, password, age, pub_sit);
    }
    else{
        manager->add_profile(email, username, password, age);
    }


    std :: cout << "OK" << std :: endl;
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