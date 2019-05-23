#include <iostream>
#include <string>
#include <vector>
#include "Reply.h"

class Comment{
public:
    Comment(std :: string init_msg, int id, int pid): msg(init_msg), comment_id(id), person_id(pid), reply_id(1){}
    int get_id(){ return comment_id; }
    void add_reply(std :: string content);
    int get_person_id(){ return person_id; }
    std :: string get_msg(){ return msg; }
    void show_comment();

private:
    std :: string msg;
    std :: vector<Reply*> replies;
    int comment_id;
    int person_id;
    int reply_id;
};