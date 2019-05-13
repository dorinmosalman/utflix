#ifndef POST_H
#define POST_H

#include <iostream>
#include <string.h>
#include "Exceptions.h"
#include "Manager.h"
#include "Command.h"

class Post : public Command{
public:
    Post(std :: vector<std :: string> words) : Command(words){}
    virtual void handle_command(Manager* manager);
protected:
    void signup(std :: vector<std :: string>, Manager* manager);
    void login(std :: vector<std :: string>, Manager* manager);

};

#endif