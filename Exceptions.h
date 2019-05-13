#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class Bad_request{
public:
    std :: string what(){ return "Bad Request"; }
};

class Bad_permission{
public:
    std :: string what(){ return "Permission Denied"; }
}; 

#endif