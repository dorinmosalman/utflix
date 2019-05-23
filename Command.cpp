#include "Command.h"



Command :: Command (std :: vector <std :: string> init_words){
    for(int i = 0 ; i < init_words.size(); i++){
        words.push_back(init_words[i]);
    }
}


int Command :: string_to_int(std :: string word){
    int result = 0;
    for(int i = 0 ; i < word.length() ; i++){
        result = result * 10 + (int(word[i]) - 48); 
    }
    return result;
}



void Command :: handle_command (Manager* manager){
    if(words[1] == "buy"){
        Buy buy;
        if(words[0] == "POST"){
            buy.post(manager, words);
        }
    }
    else if(words[1] == "signup"){
        Signup signup;
        if(words[0] == "POST"){
            signup.post(manager, words);
        }
        else{
            throw Bad_request();
        }
    }
    else if(words[1] == "login"){
        Login login;
        if(words[0] == "POST"){
            login.post(manager, words);
        }
        else{
            throw Bad_request();
        }
    }
    else if(words[1] == "films"){
        Films films;
        if(words[0] == "POST"){
            films.post(manager, words);
        }
        else if(words[0] == "PUT"){
            films.put(manager, words);
        }
        else if(words[0] == "DELETE"){
            films.delete_(manager, words);
        }
        else if(words[0] == "GET"){
            films.get(manager, words);
        }
        else{
            throw Bad_request();
        }

    }
    else if(words[1] == "followers"){
        Followers followers;
        if(words[0] == "POST"){
            followers.post(manager, words);
        }
        if(words[0] == "GET"){
            followers.get(manager, words);
        }
    }
    else if(words[1] == "money"){
        Money money;
        if(words[0] == "POST" && words.size() > 2){
            money.post(manager, words);
        }
        else if(words[0] == "POST" && words.size() == 2){
            money.post(manager);
        }
    }
    else if(words[1] == "buy"){
        Buy buy;
        if(words[0] == "POST"){
            buy.post(manager, words);
        }
    }
    else if(words[1] == "rate"){
        Rate rate;
        if(words[0] == "POST"){
            rate.post(manager, words);
        }
    }
    else if(words[1] == "notifications"){
        Notifications notifications;
        if(words[0] == "GET" && words.size() == 2){
            notifications.get(manager);
        }
        else if(words[0] == "GET" && words.size() > 2){
            notifications.get(manager, words);
        }
    }
    else if(words[1] == "comments"){
        Comments comments;
        if(words[0] == "POST"){
            comments.post(manager, words);
        }
        else if(words[0] == "DELETE"){
            comments.delete_(manager, words);
        }
        else{
            throw Bad_request();
        }
    }
    else if(words[1] == "replies"){
        Replies replies;
        if(words[0] == "POST"){
            replies.post(manager, words);
        }
        else{
            throw Bad_request();
        }
    }
    else if(words[1] == "purchased"){
        Purchased purchased;
        if(words[0] == "GET"){
            purchased.get(manager, words);
        }
        else{
            throw Bad_request();
        }
    }
    else if(words[1] == "published"){
        Published published;
        if(words[0] == "GET"){
            published.get(manager, words);
        }
        else{
            throw Bad_request();
        }
    }
    else{
        throw Bad_request();
    }

}
