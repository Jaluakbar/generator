#include <iostream>
#include "door.hpp"
#include "room.hpp"
#include <vector>
#include "generator.hpp"

int main(){
    std::cout<<"Hello, World!"<<std::endl;
    typedef std::vector<room*> graph;


    auto a = spot::bottom;

    graph new_graph = generate_rooms(6);

    for (auto g: new_graph){
        g->print();
    }


    return 0;
}