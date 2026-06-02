#pragma once
#include <vector>
#include <memory>
#include <random>
#include <iostream>

enum Weather{SUNNY,RAIN,DROUGHT};

class Entity;
class Plant;
class Herbivore;
class Carnivore;

class World{
public:
    int width=40,height=20,tick=0;
    Weather weather=SUNNY;

    std::vector<std::unique_ptr<Entity>> entities;
    std::mt19937 rng;

    World();

    void populate();
    void update();
    void render();

    bool inBounds(int x,int y);
    bool occupied(int x,int y);
    Entity* entityAt(int x,int y);

    void add(Entity* e);

    int randInt(int a,int b);
};
