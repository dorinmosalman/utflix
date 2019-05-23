#include "Replies.h"

void Replies :: post(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3)
        throw Bad_request();
    if(words[2] != "?"){
        throw Bad_request();
    }
    int i = 3;
    int film_id, comment_id;
    std :: string content;
    bool film_id_bool = false;
    bool comment_id_bool = false;
    bool content_bool = false;
    while(i < words.size()){
        if(words[i] == "film_id"){
            film_id = stoi(words[i+1]);
            film_id_bool = true;
        }
        if(words[i] == "comment_id"){
            comment_id = stoi(words[i+1]);
            comment_id_bool = true;
        }
        if(words[i] == "content"){
            content = words[i+1];
            content_bool = true;
        }
        i+=2;
    }
    if(!(film_id_bool && comment_id_bool && content_bool))
        throw Bad_request();


    Profile* publisher = manager->get_loggedin_pro();
    publisher->has_published(film_id);
    Profile* profile = manager->find_profile(manager->find_film(film_id)->find_comment(comment_id)->get_person_id());
    manager->find_film(film_id)->find_comment(comment_id)->add_reply(content);


    std :: string msg;
    msg = "Publisher " + publisher->get_user() + " with id " + std :: to_string(publisher->get_id()) + " reply to your comment.";
    profile->add_notif(msg);
}

