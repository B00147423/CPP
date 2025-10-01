#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include "Character.h"

class CharacterBuilder {
private:
    Character character;   // working copy
public:
    CharacterBuilder& setName(const std::string& name){
        character.name = name;
    }

    CharacterBuilder setClassType(const std::string& classType){
        character.classType= classType;
        return *this;
    }

    CharacterBuilder& setHP(int hp) {
        character.hp = hp;
        return *this;
    }

    CharacterBuilder& setAttack(int attack) {
        character.attack = attack;
        return *this;
    }
        CharacterBuilder& setDefense(int defense) {
        character.defense = defense;
        return *this;
    }

    CharacterBuilder& setWeapon(const std::string& weapon) {
        character.weapon = weapon;
        return *this;
    }

    Character build() {
        return character;  // returns the final product
    }

};

#endif
