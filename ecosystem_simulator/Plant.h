#pragma once
#include "Entity.h"

class Plant : public Entity{
public:
    Plant(int x,int y):Entity(x,y){}
    void update(World& world) override;
    char symbol() const override { return 'P'; }
};
