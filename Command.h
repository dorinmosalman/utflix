#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include "Exceptions.h"
#include "Manager.h"
#include "Profile.h"
#include "Film.h"
#include "Login.h"
#include "Signup.h"
#include "Films.h"
#include "Followers.h"
#include "Money.h"
#include "Buy.h"
#include "Rate.h"
#include "Notifications.h"

class Command{
public:

    Command(std :: vector<std :: string> init_words);
    void handle_command(Manager* manager);


    
protected:
    std :: vector<std :: string> words;
    
    int string_to_int(std :: string);

    // void command_valid();
  //  void signup(Manager* manager);
    // void login(Manager* manager);
    // void post(Manager* manager);
    // void put(Manager* manager);
    // void post_film(Manager* manager);
    // void edit_film(Manager* manager);

};

#endif  