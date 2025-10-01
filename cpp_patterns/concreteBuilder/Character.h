#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character {
public:
    std::string name;
    std::string classType;
    int hp;
    int attack;
    int defense;
    std::string weapon;

    void show() const {
        std::cout << "Name: " << name << "\n"
                  << "Class: " << classType << "\n"
                  << "HP: " << hp << "\n"
                  << "Attack: " << attack << "\n"
                  << "Defense: " << defense << "\n"
                  << "Weapon: " << weapon << "\n";
    }
};

#endif
