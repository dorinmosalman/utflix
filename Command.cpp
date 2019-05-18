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
    std :: cout << "word: " << word << std :: endl;
    int result = 0;
    for(int i = 0 ; i < word.length() ; i++){
        result = result * 10 + (int(word[i]) - 48); 
        std :: cout << result << std :: endl;
    }
    return result;
}



void Command :: handle_command (Manager* manager){
    // if(words[0] == "POST"){
    //     post(manager);
    // }
    // else if(words[0] == "PUT"){
    //     std :: cout << "put" << std :: endl;
    //     put(manager);
    // }
    // else if(words[0] == "GET"){
    //     //get(manager);
    // }
    // else if(words[0] == "DELETE"){
    //     //delete_(manager);
    // }
    // else{
    //     std :: cout << "POST" << std :: endl;
    //     throw Bad_request();
    // }
    if(words[1] == "signup"){
        Signup signup;
        if(words[0] == "POST"){
            signup.post(manager, words);
        }
        else{
            throw Bad_request();
        }
    }
    else if(words[1] == "login"){
        Login login;
        if(words[0] == "POST"){
            login.post(manager, words);
        }
        else{
            throw Bad_request();
        }
    }
    else if(words[1] == "films"){
        Films films;
        if(words[0] == "POST"){
            std :: cout << "post films" << std :: endl;
            films.post(manager, words);
        }
        else if(words[0] == "PUT"){
            films.put(manager, words);
        }
        else if(words[0] == "DELETE"){
            films.delete_(manager, words);
        }
        else if(words[0] == "GET"){
            films.get(manager, words);
        }
        else{
            throw Bad_request();
        }

    }
    else if(words[1] == "followers"){
        Followers followers;
        if(words[0] == "POST"){
            std :: cout << "post followers" << std :: endl;
            followers.post(manager, words);
        }
        if(words[0] == "GET"){
            followers.get(manager, words);
        }
    }
    else if(words[1] == "money"){
        std :: cout << "money \t words size= " << words.size() << std :: endl;
        Money money;
        if(words[0] == "POST" && words.size() > 2){
            std :: cout << "Post money" << std :: endl;
            money.post(manager, words);
        }
        else if(words[0] == "POST" && words.size() == 2){
            money.post(manager);
        }
    }
    else if(words[1] == "buy"){
        Buy buy;
        if(words[0] == "POST"){
            std :: cout << "buy post" << std :: endl;
            buy.post(manager, words);
        }
    }
    else if(words[1] == "rate"){
        Rate rate;
        if(words[0] == "POST"){
            std :: cout << "post rate" << std :: endl;
            rate.post(manager, words);
        }
    }
    else if(words[1] == "notifications"){
        Notifications notifications;
        if(words[0] == "GET" && words.size() == 2){
            notifications.get(manager);
        }
        else if(words[0] == "GET" && words.size() > 2){
            notifications.get(manager, words);
        }
    }
    else{
        throw Bad_request();
    }


}




// void Command :: post_film(Manager* manager){
//     // for(int i = 0 ; i < words.size() ; i++){
//     //     std :: cout << words[i] << "." << std :: endl;
//     // }
//     if(!(words[2] == "?" && words[3] == "name" && words[5] == "year" && words[7] == "length" &&
//         words[9] == "price" && words[11] == "summary" && words[13] == "director")){
//         std :: cout << "sabet ha" << std :: endl;
//         throw Bad_request(); 
//     }
//     std :: string name = words[4];
//     int year = string_to_int(words[6]);
//     int length = string_to_int(words[8]);
//     int price = string_to_int(words[10]);
//     std :: string summary = words[12];
//     std :: string director = words[14];

//     manager->add_film(manager->get_loggedin_pro(), name, year, length, price, summary, director);
//     //manager add film
// }

// void Command :: edit_film(Manager* manager){
//     std :: cout << "edit" << std :: endl;
//     if(words[3] != "film_id"){
//         std :: cout << "sabet ha" << std :: endl;
//         throw Bad_request();
//     }
//     int film_id = string_to_int(words[4]);
//     std :: cout << "words4= " << words[4] << "\t film_id= " << film_id << std :: endl;
//     Film* film = manager->find_film(film_id);
//     int i = 5;
//     std :: cout << "words size : " << words.size() << std :: endl;
//     while( i < words.size()){
//         if(words[i] == "name"){
//             film->change_name(words[i + 1]);
//             std :: cout << "name changed" << std :: endl;
//         }
//         else if(words[i] == "year"){
//             film->change_year(string_to_int(words[i + 1]));
//         }
//         else if(words[i] == "length"){
//             film->change_length(string_to_int(words[i + 1]));
//         }
//         else if(words[i] == "summary"){
//             film-> change_summary(words[i + 1]);
//         }
//         else if(words[i] == "director"){
//             film->change_director(words[i + 1]);
//         }
//         i+=2;
//     }
// }

// void Command :: put(Manager* manager){
//     if(words[2] != "?"){
//         std :: cout << "??" << std :: endl;
//         throw Bad_request();
//     }
//     if(words[1] == "films"){
//         edit_film(manager);
//     }
// }

// void Command :: post(Manager* manager){
//     if(words[2] != "?"){
//         std :: cout << "??" << std :: endl;
//         throw Bad_request();
//     }
//     if(words[1] == "signup"){
//         signup(manager);
//     }
//     else if(words[1] == "login"){
//         login(manager);
//     }
//     else if(words[1] == "films"){
//         post_film(manager);
//     }
//     else{
//         std :: cout << "signup" << std :: endl;
//         throw Bad_request();
//     }
// }