#pragma once
#include "Animal.h"

class Carnivore : public Animal{
public:
    Carnivore(int x,int y):Animal(x,y,40){}
    void update(World& world) override;
    char symbol() const override { return 'C'; }
};
