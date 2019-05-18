#include "Manager.h"
#include <vector>
#include <regex>

class Signup{
public:
    void post(Manager* manager, std :: vector<std :: string> words);
private:
    void mail_valid(std :: string mail);
    void age_valid(std :: string age);
};