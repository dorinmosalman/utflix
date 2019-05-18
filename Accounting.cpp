#include "Accounting.h"

Accounting :: Accounting(){
    // publisher_money[0] = 0;
}


bool Accounting :: publisher_exists(int pub_id){
    std :: cout << "start" << std :: endl;
    for(const auto& elem : publisher_money){
        std :: cout << elem.first << "\t" << elem.second << std :: endl;
        if(elem.first == pub_id){
            return true;
        }
    }
    std :: cout << "end" << std :: endl;
    return false;
}

int Accounting :: calculate_money(Film* film){
    std :: cout << "calculate money" << std :: endl;
    int rate = film->get_rate();
    int price = film->get_price();
    int percent;
    std :: cout << "rate" << rate << std :: endl;
    if( rate >= 0 && rate < 5)
        percent = 80;
    if(rate >= 5 && rate < 8)
        percent = 90;
    if(rate>=8 && rate <= 10)
        percent = 95;
    std :: cout << "if done " << std :: endl;
    int a = 5;
    netflix_money += (price*(100 - percent)) / 100;
    std :: cout << "done" << std :: endl;
    return (price*percent) / 100;
}

void Accounting :: add_money(Film* film){
    std :: cout << "accounting add money" << std :: endl;
    int pub_id = film->get_pub_id();
    int money = calculate_money(film);
    std :: cout << "***" << std :: endl;
    if(publisher_exists(pub_id)){
        std :: cout << "publisher exists" << std :: endl;
        std :: map<int, int> :: iterator it;
        it = publisher_money.find(pub_id);
        int m = it->second;
        publisher_money[pub_id] = money+ m;
    }
    else{
        std :: cout << "new pub " << std :: endl; 
        publisher_money[pub_id] = money;
    }
    for(const auto& elem : publisher_money){
        std :: cout << elem.first << "\t" << elem.second << std :: endl;
    }
    
}


int Accounting :: get_pub_money(int pub_id){
    for(const auto& elem : publisher_money){
        std :: cout << elem.first << "\t" << elem.second << std :: endl;
        if(elem.first == pub_id){
            return elem.second;
        }
    }
    return 0;
}