#include "Accounting.h"

Accounting :: Accounting(){
}


bool Accounting :: publisher_exists(int pub_id){
    for(const auto& elem : publisher_money){
        if(elem.first == pub_id){
            return true;
        }
    }
    return false;
}

int Accounting :: calculate_money(Film* film){
    int rate = film->get_rate();
    int price = film->get_price();
    int percent;
    if( rate >= 0 && rate < 5)
        percent = 80;
    if(rate >= 5 && rate < 8)
        percent = 90;
    if(rate>=8 && rate <= 10)
        percent = 95;
    int a = 5;
    netflix_money += (price*(100 - percent)) / 100;
    return (price*percent) / 100;
}

void Accounting :: add_money(Film* film){
    int pub_id = film->get_pub_id();
    int money = calculate_money(film);
    if(publisher_exists(pub_id)){
        std :: map<int, int> :: iterator it;
        it = publisher_money.find(pub_id);
        int m = it->second;
        publisher_money[pub_id] = money+ m;
    }
    else{
        publisher_money[pub_id] = money;
    }
}


int Accounting :: get_pub_money(int pub_id){
    for(const auto& elem : publisher_money){
        if(elem.first == pub_id){
            return elem.second;
        }
    }
    return 0;
}