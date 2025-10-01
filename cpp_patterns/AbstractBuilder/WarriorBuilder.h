#ifndef WARRIOR_bUILDER_H
#define WARRIOR_bUILDER_H

#include <string>
#include "CharacterBuilder.h"


class WarriorBuilder : public CharacterBuilder {
private:
    Character* character;
public:
    WarriorBuilder() { character = new Character(); }
    void setName(const std::string& name) override { character->name = name; }
    void setClassType() override { character->classType = "Warrior"; }
    void setHP() override { character->hp = 150; }
    void setAttack() override { character->attack = 50; }
    void setDefense() override { character->defense = 40; }
    void setWeapon() override { character->weapon = "Sword"; }

    Character* getResult() override { return character; }
};


#endif