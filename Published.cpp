#include "Published.h"

void Published :: get(Manager* manager, std :: vector<std :: string> words){

    Profile* profile = manager->get_loggedin_pro();
    profile->show_published(words);

}