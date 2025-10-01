#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>


class Character{
public:
    std::string name;
    std::string classType; 
    int hp, attack, defense;
    std::string weapon;
    void show() {
            std::cout << "Name: " << name << "\n"
             << "Class: " << classType << "\n"
             << "HP: " << hp << "\n"
             << "Attack: " << attack << "\n"
             << "Defense: " << defense << "\n"
             << "Weapon: " << weapon << "\n";
    }
};

#endif