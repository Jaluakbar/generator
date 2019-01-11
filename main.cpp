#include <iostream>
#include "door.hpp"
#include "room.hpp"
#include <vector>
#include "generator.hpp"

int main(){
    std::cout<<"Hello, World!"<<std::endl;
    typedef std::vector<room*> graph;

    graph new_graph = generate_rooms(15);

    for (auto g: new_graph){
        g->print();
    }

    return 0;
}