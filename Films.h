#ifndef FILMS_H
#define FILMS_H

#include "Manager.h"
#include "Exceptions.h"
#include "Profile.h"
#include <vector>

class Films{
public: 
    void post(Manager* manager, std :: vector<std :: string> words);
    void put(Manager* manager, std :: vector<std :: string> words);
    void delete_(Manager* manager, std :: vector<std :: string> words);
    void get(Manager* manager, std :: vector<std :: string> words);
};

#endif