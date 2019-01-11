//
// Created by jalua on 10/01/2019.
//

#ifndef GENERATOR_ROOM_HPP
#define GENERATOR_ROOM_HPP

#include <vector>
#include "door.hpp"
#include <iostream>

class room{
private:
    int id;
    int x,y;
    std::vector<room*> connection;
public:
    room(int id, int x, int y):
        id(id),
        x(x),
        y(y)
    {}

    int get_id() const{
        return id;
    }

    int get_x() const {
        return x;
    }

    int get_y() const{
        return y;
    }

    void add_edge(room* r){
        std::cout << "added edge " << r->get_id() <<std::endl;
        connection.push_back(r);
    }

    bool is_location(int tmp_x, int tmp_y){
        return (x == tmp_x && y == tmp_y);
    }

    void print(){
        std::cout << id << '(' << x << ',' << y << "): ";
        for(auto r : connection){
            std:: cout << r->get_id() << ',';
        }
        std::cout << std::endl ;
    }
};
#endif //GENERATOR_ROOM_HPP
