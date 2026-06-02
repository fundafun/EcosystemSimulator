#include "Plant.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "World.h"
#include <cmath>

void Animal::moveRandom(World& world){
    int nx=x+world.randInt(-1,1);
    int ny=y+world.randInt(-1,1);

    if(world.inBounds(nx,ny)){
        x=nx;
        y=ny;
    }
}

void Plant::update(World& world){
    int chance = world.weather==RAIN?12:world.weather==DROUGHT?2:6;

    if(world.randInt(0,100)<chance){
        int nx=x+world.randInt(-1,1);
        int ny=y+world.randInt(-1,1);

        if(world.inBounds(nx,ny) && !world.occupied(nx,ny))
            world.add(new Plant(nx,ny));
    }
}

void Herbivore::update(World& world){
    energy--;

    Entity* e = world.entityAt(x,y);

    for(auto& ptr:world.entities){
        auto target=ptr.get();
        if(target->alive && target->symbol()=='P' &&
           abs(target->x-x)<=1 && abs(target->y-y)<=1){
            target->alive=false;
            energy+=10;
            break;
        }
    }

    moveRandom(world);

    if(energy>40 && world.randInt(0,100)<8){
        world.add(new Herbivore(x,y));
        energy-=15;
    }

    if(energy<=0) alive=false;
}

void Carnivore::update(World& world){
    energy--;

    for(auto& ptr:world.entities){
        auto target=ptr.get();

        if(target->alive && target->symbol()=='H' &&
           abs(target->x-x)<=1 && abs(target->y-y)<=1){
            target->alive=false;
            energy+=20;
            break;
        }
    }

    moveRandom(world);

    if(energy>60 && world.randInt(0,100)<6){
        world.add(new Carnivore(x,y));
        energy-=20;
    }

    if(energy<=0) alive=false;
}
