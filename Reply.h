#ifndef REPLY_H
#define REPLY_H

#include <iostream>
#include <string>

class Reply{
public:
    Reply(std :: string msg, int init_id) : content(msg), reply_id(init_id){}
    std :: string get_msg(){ return content; }
    void show_reply();

protected:
    std :: string content;
    int reply_id;

};

#endif