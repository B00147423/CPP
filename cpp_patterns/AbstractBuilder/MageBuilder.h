#ifndef MAGE_BUILDER_H
#define MAGE_BUILDER_H

#include "CharacterBuilder.h"

class MageBuilder : public CharacterBuilder {
private:
    Character* character;
public:
    MageBuilder() { character = new Character(); }

    void setName(const std::string& name) override { character->name = name; }
    void setClassType() override { character->classType = "Mage"; }
    void setHP() override { character->hp = 100; }
    void setAttack() override { character->attack = 70; }
    void setDefense() override { character->defense = 20; }
    void setWeapon() override { character->weapon = "Staff"; }

    Character* getResult() override { return character; }
};

#endif
