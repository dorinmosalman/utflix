#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include <string>

class Notification{
public:
    Notification(std :: string init_msg): message(init_msg), read_sit(false){}
    std :: string get_msg(){ return message; }
    bool is_read(){ return read_sit; }
    void read(){ read_sit = true; }

private:
    std :: string message;
    bool read_sit;
};


#endif