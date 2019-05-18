#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class Bad_request : public std :: exception{
public:
    virtual const char* what() const throw(){ return "Bad Request"; }
};

class Bad_permission : public std :: exception{
public:
    virtual const char* what() const throw(){ return "Permission Denied"; }
}; 

class Error_exception : public std:: exception{
    virtual const char* what() const throw(){ return "ERROR!"; }
};

class doesnt_exist : public std :: exception{};

#endif