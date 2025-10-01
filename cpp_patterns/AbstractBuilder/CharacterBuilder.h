/*
## 3. Builder

🎯 **Goal**: Build a customizable RPG character step by step.

### Requirements

- Product: `Character` with fields → `name`, `classType`, `hp`, `attack`, `defense`, `weapon`.
    
- Abstract builder: `CharacterBuilder` with methods to set these fields.
    
- Concrete builders: `WarriorBuilder`, `MageBuilder` (with different defaults).
    
- Director (optional): `CharacterDirector` that builds a standard Warrior or Mage.
    
- Client: Use both ways:
    
    - Through the director (preset Warrior/Mage).
        
    - Manually by setting each part.
*/

#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include "Character.h"
#include <string>
class CharacterBuilder {
public:
    virtual ~CharacterBuilder(){}
    virtual void setName(const std::string& name) = 0;
    virtual void setClassType() = 0;
    virtual void setHP() = 0;
    virtual void setAttack() = 0;
    virtual void setDefense() = 0;
    virtual void setWeapon() = 0;

    virtual Character* getResult() = 0;

};

#endif