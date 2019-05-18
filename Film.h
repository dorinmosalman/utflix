#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <map>
#include <vector>
#include "Comment.h"

class Film{
public:
    Film(std :: string init_name, int init_year, int init_length, int init_price,
    std :: string init_summary, std :: string init_director, int init_id, int init_pub_id)
        : name(init_name), year(init_year), length(init_length), 
        price(init_price), summary(init_summary), director(init_director), id(init_id), rate(0), pub_id(init_pub_id), comment_id(1){}
    void change_name(std :: string init_name){ name = init_name; }
    void change_year(int init_year){ year = init_year; }
    void change_length(int init_length){ length = init_length; }
    void change_summary(std :: string init_summary){ summary = init_summary; }
    void change_director(std :: string init_director){ director = init_director; }
    int get_id(){ return id; }
    std :: string get_name(){ return name; }
    int get_rate(){ return rate; }
    int get_price(){ return price; }
    int get_pub_id(){ return pub_id; }
    void score(int score, int pro_id);
    void add_comment(std :: string msg);

    void show_film();

private:
    std :: string name;
    int year;
    int length;
    int price;
    int id;
    int rate;
    std :: map<int, int> rates;
    std :: string summary;
    std :: string director;
    int pub_id;
    std :: vector<Comment*> comments;
    int comment_id;
};

#endif