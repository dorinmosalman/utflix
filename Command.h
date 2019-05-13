#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include "Exceptions.h"
#include "Manager.h"
#include "Profile.h"

class Command{
public:

    Command(std :: vector<std :: string> init_words);
    void handle_command(Manager* manager);


    
protected:
    std :: vector<std :: string> words;
    
    int string_to_int(std :: string);

    void command_valid();
    void signup(Manager* manager);
    void login(Manager* manager);
    void post(Manager* manager);
    void post_film(Manager* manager);

};

#endif  