#pragma once
#include "Animal.h"

class Herbivore : public Animal{
public:
    Herbivore(int x,int y):Animal(x,y,25){}
    void update(World& world) override;
    char symbol() const override { return 'H'; }
};
