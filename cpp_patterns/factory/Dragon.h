#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"

class Dragon : public Enemy {
public:
    void Attack() override {
        std::cout << "Dragon breathes fire!" << std::endl;
    }
};

#endif
