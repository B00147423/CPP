#include "CharacterBuilder.h"


int main(){
    Character warrior = CharacterBuilder()
        .setName("Conan")
        .setClassType("Warrior")
        .setHP(150)
        .setAttack(50)
        .setDefense(40)
        .setWeapon("Sword")
        .build();
    warrior.show();
    return 0;

}