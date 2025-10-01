#ifndef TROLL_H
#define TROLL_H
#include "Enemy.h"

class Troll : public Enemy {
public:
    void Attack() override {
        std::cout << "Troll smashes with a club!" << std::endl;
    }
};

#endif
