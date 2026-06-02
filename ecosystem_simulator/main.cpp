#include "World.h"

int main(){
    World world;

    world.populate();

    while(true){
        world.update();
        world.render();
    }
}
