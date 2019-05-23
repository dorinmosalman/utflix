#include "Purchased.h"

void Purchased :: get(Manager* manager, std :: vector<std :: string> words){

    Profile* profile = manager->get_loggedin_pro();
    std :: cout << FILM_HEADER << std :: endl;
    profile->show_purchased_films(words);
}