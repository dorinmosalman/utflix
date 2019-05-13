#include "Profile.h"

bool Profile :: check_password(int pass){
    if(pass == password)
        return true;
    return false;
}

void Profile :: login(int pass){
    if(pass == password)
        login_sit = true;
    else
        throw Bad_request();
}