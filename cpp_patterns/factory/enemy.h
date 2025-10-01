#ifndef ENEMY_H
#define  ENEMY_H
#include <iostream>
#include <string>


class Enemy{
public:
    virtual ~Enemy() {}
    virtual void Attack() = 0; // pure virtual

};
#endif