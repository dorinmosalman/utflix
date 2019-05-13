#include "Command.h"


// std :: vector<std :: string> Command :: read_line(std :: string line){
//     int from = 0; 
//     int l = 0;
//     std :: string word;
//     std :: vector < std :: string> words;
//     while(from + l < line.length()){
//         while(line[from + l] != ' '){
//             word = line.substr(from , ++l);
//         }
//         words.push_back(word);
//         from = from + l + 1;
//     }
//     return words;
// }


Command :: Command (std :: vector <std :: string> init_words){
    for(int i = 0 ; i < init_words.size(); i++){
        words.push_back(init_words[i]);
    }
}


int Command :: string_to_int(std :: string word){
    int result;
    for(int i = 0 ; i < word.length() ; i++){
        result = result * 10 + (int(word[i]) - 48); 
    }
    return result;
}

void Command :: post(Manager* manager){
    for(int i = 0 ; i < words.size() ; i++){
        std :: cout << words[i] << "." << std :: endl;
    }
    if(words[2] != "?"){
        std :: cout << "??" << std :: endl;
        throw Bad_request();
    }
    if(words[1] == "signup"){
        signup(manager);
    }
    else if(words[1] == "login"){
        login(manager);
    }
    else if(words[1] == "films"){
        post_film(manager);
    }
    else{
        std :: cout << "signup" << std :: endl;
        throw Bad_request();
    }
}


void Command :: handle_command (Manager* manager){
    if(words[0] == "POST"){
        post(manager);
    }
    else if(words[0] == "PUT"){
    //    put(manager);
    }
    else if(words[0] == "GET"){
        //get(manager);
    }
    else if(words[0] == "DELETE"){
        //delete_(manager);
    }
    else{
        std :: cout << "POST" << std :: endl;
        throw Bad_request();
    }
    //if(words[0] == "signup"){
    //     signup(manager);
    // }
    // else if(words[2] == "login"){
    //     login(manager);
    // }
    // else{
    //     std :: cout << "signup" << std :: endl;
    //     throw Bad_request();
    // }
}

void Command :: signup(Manager* manager){
    if(!(words[2] == "?" && words[3] == "email" && words[5] == "username" && words[7] == "password" 
        && words[9] == "age")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    std :: cout << "signup in manager" << std :: endl;
    
    std :: string email = words[4];
    std :: string username = words[6];
    int password = string_to_int(words[8]);
    int age = string_to_int(words[10]);
//    bool pub_sit;
    if(words.size() == 12){
        bool pub_sit;
        if(words[11] != "publisher")
            throw Bad_request();
        else if(words[12] == "true"){
            pub_sit = true;
            std :: cout << "publisher situation is true" << std :: endl;
        }
        else{
            pub_sit = false;
            std :: cout << "publisher situation is false" << std :: endl;
        }
        std :: cout << "add profile" << std :: endl;
        manager->add_profile(email, username, password, age, pub_sit);
    }
    else{
        std :: cout << "add profile" << std :: endl;
        manager->add_profile(email, username, password, age);
    }
}

void Command :: login (Manager* manager){
    if(!(words[2] == "?" && words[3] == "username" && words[5] == "password")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request();
    }
    std :: string username = words[4];
    int password = string_to_int (words[6]);
    manager->login(username, password); 
}

void Command :: post_film(Manager* manager){
    // for(int i = 0 ; i < words.size() ; i++){
    //     std :: cout << words[i] << "." << std :: endl;
    // }
    if(!(words[2] == "?" && words[3] == "name" && words[5] == "year" && words[7] == "length" &&
        words[9] == "price" && words[11] == "summary" && words[13] == "director")){
        std :: cout << "sabet ha" << std :: endl;
        throw Bad_request(); 
    }
    std :: string name = words[4];
    int year = string_to_int(words[6]);
    int length = string_to_int(words[8]);
    int price = string_to_int(words[10]);
    std :: string summary = words[12];
    std :: string director = words[14];

    manager->add_film(manager->get_loggedin_pro(), name, year, length, price, summary, director);
    //manager add film
}