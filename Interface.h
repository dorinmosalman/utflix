#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string.h>

#include "Manager.h"
#include "Exceptions.h"
#include "Command.h"

class Interface{
public:
    // std :: string get_command();
    // void read_command(std :: string line);
    // std :: string get_word(std :: string line, int count);
    Interface();
    void get_command();
    void run();

    std :: vector<std :: string>* read_line(std :: string line);
protected:
    // void post(std :: vector<std :: string> line);
    // void put(std :: vector<std :: string>);
    // void get(std :: vector<std :: string>);
    // void del(std :: vector<std :: string>);

    Manager* manager;

};

#endif