#include <iostream>
#include <vector>
#include "Manager.h"

class Notifications{
public:
    void get(Manager* manager);
    void get(Manager* manager, std :: vector<std :: string> words);
};