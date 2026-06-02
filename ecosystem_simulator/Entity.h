#pragma once
class World;

class Entity{
public:
    int x,y;
    bool alive=true;

    Entity(int x,int y):x(x),y(y){}
    virtual ~Entity() = default;

    virtual void update(World& world)=0;
    virtual char symbol() const=0;
};
