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
#include "Comments.h"
#include "Replies.h"
#include "Published.h"
#include "Purchased.h"

class Command{
public:

    Command(std :: vector<std :: string> init_words);
    void handle_command(Manager* manager);


    
protected:
    std :: vector<std :: string> words;
    
    int string_to_int(std :: string);


};

#endif  