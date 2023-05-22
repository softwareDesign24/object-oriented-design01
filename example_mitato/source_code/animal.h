// animal.h
//

#pragma once

class Animal {

private:
    int ID;
    char animal_type;
    float weight;

public:
    
    // constructor
    Animal(int, char, float);

    // destructor
    ~Animal();
    
    int get_ID();
    char get_animal_type();
    float get_weight();
};

Animal::Animal(int my_ID, char my_animal_type, float my_weight) {
    ID = my_ID;
    animal_type = my_animal_type;
    weight = my_weight;
}

Animal::~Animal() {
    // add instructions
}

int Animal::get_ID() {
    return ID;
}


char Animal::get_animal_type() {
    return animal_type;
}


float Animal::get_weight() {
    return weight;
}