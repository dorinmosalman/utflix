#ifndef PURCHASED_H
#define PURCHASED_H

#include <iostream>
#include <vector>
#include <string>
#include "Manager.h"
#include "Film.h"
#include "Exceptions.h"
#include "Profile.h"


class Purchased{
public:
    void get(Manager* manager, std :: vector<std :: string> words);
};

#endif