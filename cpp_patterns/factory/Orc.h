#ifndef ORC_H
#define ORC_H
#include "Enemy.h"

class Orc : public Enemy {
public:
    void Attack() override {
        std::cout << "Orc swings an axe!" << std::endl;
    }
};

#endif
