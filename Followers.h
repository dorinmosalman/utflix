#include"Exceptions.h"
#include "Manager.h"
#include <vector>
#include <string>
#include <iostream>

class Followers{
public:
    void post(Manager* manager, std :: vector<std :: string> words);
    void get(Manager* manager, std :: vector<std :: string> words);
};