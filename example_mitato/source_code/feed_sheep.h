// feed_sheep.h
//

#pragma once

#include "Feeder.h"
#include <ctime> // time library

extern int feeding_turn; // it is the variable also located in main.cpp and <feeder*.h> files


class feed_sheep: public Feeder {
private:
    const int typical_weight = 50;
    const int max_feeding_times = 3;

protected:
    bool is_time_to_eat();
    bool is_overweight(Animal&);
};


bool feed_sheep::is_time_to_eat() {
    bool temp = false;

    time_t get_time_now;
    get_time_now = time(0); // initialize get_time    
    tm* ltm = localtime(&get_time_now); // local time

    // if it's day and sheep have been fed <= max feeding times
    if ((ltm->tm_hour >= 7) && (ltm->tm_hour < 19) && (feeding_turn < max_feeding_times)) 
    {
        temp = true;
    }
    else { temp = false; }

    return temp;
}

bool feed_sheep::is_overweight(Animal& a) {
    bool temp = false;

    if (a.get_weight() <= typical_weight * 1.2) { 
        temp = false; 
    }
    else temp = true;

    return temp;
}