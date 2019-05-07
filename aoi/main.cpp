#include<vector>
#include "entity.h"
#include "AOIGrid.h"

using namespace AOI;

int main(){
    int width = 32;
    int height = 32;

    std::vector<Entity*> entities;

    auto aoi = AOIGrid(width, height);
    int idx = 1;
    for(int i = 0; i< width; i=i+2){
        for(int j = 0; j< height; j=j+2){
            Entity* tmp = new Entity(idx, i, j);
            idx++;
            entities.push_back(tmp);
            aoi.Enter(*tmp);
        }
    }

    Entity entity(111111, 2,3);
    aoi.Enter(entity);
    for (int i = 0; i < 10; i++){
        int x = entity.x()+1;
        int y = entity.y()+1;
        aoi.Move(entity, x, y);
        entity.set_x(x);
        entity.set_y(y);
    }
}

//g++ -o test Entity.cpp AOIGrid.cpp main.cpp --std=c++11