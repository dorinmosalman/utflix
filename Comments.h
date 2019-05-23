#include <iostream>
#include <vector>
#include <string>
#include "Film.h"
#include "Manager.h"
#include "Exceptions.h"
#include "Profile.h"


class Comments{
public:
    void post(Manager* manager, std :: vector<std :: string> words);
    void delete_(Manager* manager, std :: vector<std :: string> words);
private:

};