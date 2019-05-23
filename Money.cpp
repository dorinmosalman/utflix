#include "Money.h"

void Money :: post(Manager* manager, std :: vector<std :: string> words){
    if(words.size() < 3)
        throw Bad_request();
    if(!(words[2] == "?" && words[3] == "amount")){
        throw Bad_request();
    }
    int amount = stoi(words[4]);
    manager->get_loggedin_pro()->add_money(amount);
    std :: cout << "OK" << std :: endl;
}

void Money :: post(Manager* manager){
    Profile* loggedin_pro = manager->get_loggedin_pro();
    loggedin_pro->is_publisher();
    int pro_id = loggedin_pro->get_id();
    manager->pub_get_money(pro_id);
    std :: cout << "OK" << std :: endl;
}
