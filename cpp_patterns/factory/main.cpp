#include "EnemyFactory.h"

int main() {
    auto e1 = EnemyFactory::CreateEnemy("orc");
    auto e2 = EnemyFactory::CreateEnemy("troll");
    auto e3 = EnemyFactory::CreateEnemy("dragon");

    e1->Attack();
    e2->Attack();
    e3->Attack();

    return 0;
}
