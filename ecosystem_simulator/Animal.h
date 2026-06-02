#pragma once
#include "Entity.h"

class Animal : public Entity{
public:
    int energy;

    Animal(int x,int y,int e):Entity(x,y),energy(e){}
    void moveRandom(World& world);
};
