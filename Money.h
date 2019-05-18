#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <vector>
#include "Exceptions.h"
#include "Manager.h"

class Money{
public:
    void post(Manager* manager, std :: vector<std :: string> words);
    void post(Manager* manager);
};

#endif