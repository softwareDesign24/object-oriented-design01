// feed_goats.h
//

#pragma once

#include "Feeder.h"
#include <ctime> // time library

extern int feeding_turn; // it is the variable also located in main.cpp and <feeder*.h> files


class feed_goats : public Feeder {
private:
    const int typical_weight = 30;
    const int max_feeding_times = 4;

protected:
    bool is_time_to_eat();
    bool is_overweight(Animal&);
};


bool feed_goats::is_time_to_eat() {
    bool temp = false;

    time_t get_time_now;
    get_time_now = time(0); // initialize get_time    
    tm* ltm = localtime(&get_time_now); // local time

    // if it's day and sheep have been fed <= max feeding times
    if ((ltm->tm_hour >= 8) && (ltm->tm_hour <= 20) && (feeding_turn < max_feeding_times))
    {
        temp = true;
    }
    else { temp = false; }

    return temp;
}

bool feed_goats::is_overweight(Animal& a) {
    bool temp = false;

    if (a.get_weight() <= typical_weight * 1.15) {
        temp = false;
    }
    else temp = true;

    return temp;
}