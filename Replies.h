#ifndef REPLIES_H
#define REPLIES_H

#include <iostream>
#include <vector>
#include <string>
#include "Manager.h"
#include "Reply.h"
#include "Profile.h"

class Replies{
public:
    void post(Manager* manager, std :: vector<std :: string> words);
};

#endif