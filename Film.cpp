#include "Film.h"

void Film :: show_film(){
    std :: cout << "Details of Film " << name << std :: endl <<
    "Id =" << id << std :: endl <<
    "Director = " << director << std :: endl <<
    "Length = " << length << std :: endl <<
    "Year = " << year << std :: endl <<
    "Summary = " << summary << std :: endl <<
    "rate = " << rate << std :: endl <<
    "price = " << price << std :: endl;
    //CONTINUE
}

void Film :: score(int score, int pro_id){
    rates[pro_id] = score;
    int sum = 0;

    for(const auto& elem : rates){
        std :: cout << elem.first << "\t" << elem.second << std :: endl;
        sum += elem.second;
    }

    rate = sum / (rates.size());

    //SEND NOTIFICATION
}

void Film :: add_comment(std :: string msg){
    comments.push_back(new Comment(msg, comment_id));
    comment_id++;
}