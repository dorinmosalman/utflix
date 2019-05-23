#include "Interface.h"


Interface :: Interface(){
    manager = new Manager();
}

std :: vector<std :: string>* Interface :: read_line(std :: string line){
    int from = 0; 
    int l = 0;
    std :: string word;
    std :: vector <std :: string>* words = new std :: vector <std :: string>;
    while(from  < line.length()){
        l = 0;
        while(line[from + l] != ' ' && from+l < line.length()){
            word = line.substr(from , ++l);
        }
        if(word != "\0")
            words->push_back(word);
        word = "\0";
        from = from + l + 1;
    }
    return words;
}


void Interface :: run(){
    std :: string line;
    while(getline(std :: cin, line)){
        if(line == "" ){
            continue;
        }
        try{
            std :: vector<std :: string> *words;
            words = read_line(line);
            Command command(*words);
            command.handle_command(manager);
        }catch(Bad_request ex){
            std :: cout << ex.what() << std :: endl;
        }
        catch(Bad_permission ex){
            std :: cout << ex.what() << std :: endl;
        }
        catch(Not_found ex){
            std :: cout << ex.what() << std :: endl;
        }

    }
}
