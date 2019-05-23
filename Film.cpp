#include "Film.h"

void Film :: show_film(){
    std :: cout << "Details of Film " << name << std :: endl <<
    "Id = " << id << std :: endl <<
    "Director = " << director << std :: endl <<
    "Length = " << length << std :: endl <<
    "Year = " << year << std :: endl <<
    "Summary = " << summary << std :: endl <<
    "rate = " << rate << std :: endl <<
    "price = " << price << std :: endl << std :: endl;
    std :: cout << "Comments" << std :: endl;
    show_comments();
}

void Film :: score(int score, int pro_id){
    rates[pro_id] = score;
    int sum = 0;

    for(const auto& elem : rates){
        sum += elem.second;
    }

    rate = sum / (rates.size());

}

void Film :: add_comment(std :: string msg, int person_id){
    comments.push_back(new Comment(msg, comment_id, person_id));
    comment_id++;
}

int Film :: get_order(int comment_id){
    int i = 0;
    for(i = 0; i < comments.size(); i++){
        if(comment_id == comments[i]->get_id()){
            return i;
        }
    }
    throw Bad_request();
}

void Film :: delete_comment(int comment_id){
    int order = get_order(comment_id);
    delete comments[order];
    comments.erase(comments.begin() + order);
}

Comment* Film  :: find_comment(int comment_id){
    for(int i = 0; i < comments.size(); i++){
        if(comments[i]->get_id() == comment_id)
            return comments[i];
    }
    throw Not_found();
}

void Film :: view_comments(){
    for(int i = 0; i <comments.size(); i++){
        std :: cout << "id= " << comments[i]->get_id() << "\t" << comments[i]->get_msg() << std :: endl;
    }
}

void Film :: show_comments(){
    for(int i = 0; i < comments.size(); i++){
        comments[i]->show_comment();
    }
}


bool Film :: is_qualified(std :: vector<std :: string> words){
    int i = 3;
    while(i < words.size()){
        if(words[i] == "name"){
            if(name != words[i+1]){
                return false;
            }
        }
        else if(words[i] == "min_rate"){
            if(rate < stoi(words[i+1])){
                return false;
            }
        }
        else if(words[i] == "min_year"){
            if(year < stoi(words[i+1])){
                return false;
            }
        }
        else if(words[i] == "price"){
            if(price != stoi(words[i+1])){
                return false;
            }
        }
        else if(words[i] == "max_year"){
            if(year > stoi(words[i+1])){
                return false;
            }
        }
        else if(words[i] == "director"){
            if(director != words[i+1]){
                return false;
            }
        }
        
        i+=2;
    }
    return true;
}


void Film :: view_film(){
    std :: cout << id << SEPARATOR << 
    name << SEPARATOR <<
    length << SEPARATOR << 
    price << SEPARATOR <<
    rate << SEPARATOR << 
    year << SEPARATOR <<
    director;
}

void Film :: view_for_recoms(){
    std :: cout << id << SEPARATOR <<
    name << SEPARATOR <<
    length << SEPARATOR <<
    director << std :: endl;
}