#include "Interface.h"


Interface :: Interface(){
    manager = new Manager();
}

std :: vector<std :: string>* Interface :: read_line(std :: string line){
    std :: cout << "**" << std :: endl;
    int from = 0; 
    int l = 0;
    std :: string word;
    std :: vector <std :: string>* words = new std :: vector <std :: string>;
    std :: cout << "new vector made" << std :: endl;
    while(from  < line.length()){
        l = 0;
        while(line[from + l] != ' ' && from+l < line.length()){
            word = line.substr(from , ++l);
        }
        if(word != "\0")
            words->push_back(word);
        word = "\0";
        from = from + l + 1;
     //   l = 0;
    }
    // for(int i = 0 ; i < words->size() ; i++){
    //     std :: cout << (*words)[i] << "." << std :: endl;
    // }
    return words;
}


void Interface :: run(){
    std :: string line;
    int line_count = 0;
    while(getline(std :: cin, line)){
        std :: cout << "line : " << line_count <<  std :: endl;
        try{
            std :: vector<std :: string> *words;
            std :: cout << "vector made" << std :: endl;
            words = read_line(line);
            std :: cout << "lines read" << std :: endl;
            // for(int i = 0 ; i < words.size() ; i++)
            //     std :: cout << words[i]  << "."<< std :: endl;
            Command command(*words);
            command.handle_command(manager);
        }catch(Bad_request ex){
            std :: cout << ex.what() << std :: endl;
        }catch(Bad_permission ex){
            std :: cout << ex.what() << std :: endl;
        }
        line_count++;
    }
    std :: cout << "*********" << std :: endl;
    manager->view_profiles();
}