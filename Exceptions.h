#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class Bad_request : public std :: exception{
public:
   virtual const char* what(){ return "Bad Request"; }
};

class Bad_permission : public std :: exception{
public:
    virtual const char* what() const throw(){ return "Permission Denied"; }
}; 

class Not_found : public std :: exception{
public:
    virtual const char* what() const throw(){ return "Not Found"; }
};
#endif