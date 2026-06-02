#include "World.h"
#include "Entity.h"
#include "Plant.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include <algorithm>
#include <chrono>
#include <thread>

World::World():rng(std::random_device{}()){}

int World::randInt(int a,int b){
    std::uniform_int_distribution<> d(a,b);
    return d(rng);
}

void World::add(Entity* e){
    entities.emplace_back(e);
}

bool World::inBounds(int x,int y){
    return x>=0 && y>=0 && x<width && y<height;
}

bool World::occupied(int x,int y){
    for(auto& e:entities)
        if(e->alive && e->x==x && e->y==y)
            return true;
    return false;
}

Entity* World::entityAt(int x,int y){
    for(auto& e:entities)
        if(e->alive && e->x==x && e->y==y)
            return e.get();
    return nullptr;
}

void World::populate(){
    for(int i=0;i<120;i++) add(new Plant(randInt(0,width-1),randInt(0,height-1)));
    for(int i=0;i<20;i++) add(new Herbivore(randInt(0,width-1),randInt(0,height-1)));
    for(int i=0;i<7;i++) add(new Carnivore(randInt(0,width-1),randInt(0,height-1)));
}

void World::update(){
    tick++;

    if(tick%30==0) weather=(Weather)randInt(0,2);

    size_t n=entities.size();
    for(size_t i=0;i<n;i++)
        if(entities[i]->alive)
            entities[i]->update(*this);

    entities.erase(
        std::remove_if(
            entities.begin(),entities.end(),
            [](auto& e){return !e->alive;}
        ),
        entities.end()
    );
}

void World::render(){
    std::cout<<"\x1B[2J\x1B[H";

    std::vector<std::string> grid(height,std::string(width,'.'));

    int p=0,h=0,c=0;

    for(auto& e:entities){
        if(!e->alive) continue;
        grid[e->y][e->x]=e->symbol();

        if(e->symbol()=='P') p++;
        if(e->symbol()=='H') h++;
        if(e->symbol()=='C') c++;
    }

    for(auto&s:grid) std::cout<<s<<"\n";

    std::string w = weather==SUNNY?"Sunny":weather==RAIN?"Rain":"Drought";

    std::cout<<"\nPlants:"<<p
             <<" Herbivores:"<<h
             <<" Carnivores:"<<c
             <<" Tick:"<<tick
             <<" Weather:"<<w<<"\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(120));
}
