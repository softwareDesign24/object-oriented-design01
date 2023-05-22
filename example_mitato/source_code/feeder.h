// feeder.h
//


#pragma once

#include "animal.h"
#include <vector>
#include <iostream>


using namespace std;
int feeding_turn = 0; // it is the variable also located in main and <feeder*.h> files


class Feeder {
protected:
    vector<Animal> animal_team;

    virtual bool is_time_to_eat() = 0;
    virtual bool is_overweight(Animal&) = 0;

public:
    void set_team(vector<Animal>); 
    bool feed_alarm();
};


void Feeder::set_team(vector<Animal> input_v) {
    animal_team = input_v;
}


bool Feeder::feed_alarm() {

    bool output;

    for (auto i = animal_team.begin(); i != animal_team.end(); i++) {

        // check if it's time for the animal to eat and it isn't overweight
        if (this->is_time_to_eat() && (!this->is_overweight(*i))) {
            output = true;
            cout << endl << "You should feed animal: " << i->get_ID() << endl;
        }
        else { output = false; }
    }


    return output;
}