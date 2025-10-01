#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include <memory>
#include <string>
#include "Orc.h"
#include "Troll.h"
#include "Dragon.h"

class EnemyFactory {
public:
    static std::unique_ptr<Enemy> CreateEnemy(const std::string& type) {
        if (type == "orc")    return std::make_unique<Orc>();
        if (type == "troll")  return std::make_unique<Troll>();
        if (type == "dragon") return std::make_unique<Dragon>();
        return nullptr;
    }
};

#endif