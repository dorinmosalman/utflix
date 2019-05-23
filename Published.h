#ifndef PUBLISHED_H
#define PUBLISHED_H

#include <iostream>
#include <vector>
#include <string>
#include "Manager.h"
#include "Film.h"
#include "Exceptions.h"
#include "Profile.h"
class Published{
public:
    void get(Manager* manager, std  :: vector<std :: string> words);
};

#endif