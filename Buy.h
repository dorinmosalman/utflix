#ifndef BUY_H
#define BUY_H

#include <iostream>
#include <vector>
#include <string>
#include "Exceptions.h"
#include "Manager.h"
#include "Film.h"

class Buy{
public:
    void post(Manager* manager, std :: vector<std :: string> words);
};


#endif