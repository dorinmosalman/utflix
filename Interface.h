#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string.h>

#include "Manager.h"
#include "Exceptions.h"
#include "Command.h"

class Interface{
public:
    Interface();
    void get_command();
    void run();

    std :: vector<std :: string>* read_line(std :: string line);
protected:

    Manager* manager;

};

#endif