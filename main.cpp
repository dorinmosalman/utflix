#include <iostream>
#include <string>
using namespace std;

#include "Interface.h"


int main(){
    // Manager manager;
    // manager.add_profile("mail", "user", 123);
    // manager.add_profile("maill", "userr", 123, true);
    // manager.view_profiles();
    // manager.login("user", 123);
    // manager.login("user",12);
    // manager.add_profile("mail", "user", 123);
    // Interface interface;
    // vector<string> words;
    // words = interface.read_line("dorin mosalman");
    // for(int i = 0 ; i < words.size() ; i++){
    //     cout << words[i] << endl;
    // }

    // string line;
    // try{
    //     while(getline(cin, line)){
    //         Command command(line);
    //         command.handle_command();
    //     }
    // }catch(Bad_request ex){
    //     cout << ex.what() << endl;
    // }
    Interface interface;
    interface.run();



    return 0;
}