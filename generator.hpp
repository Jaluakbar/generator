//
// Created by jalua on 10/01/2019.
//

#ifndef GENERATOR_GENERATOR_HPP
#define GENERATOR_GENERATOR_HPP

#include "room.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

std::vector<room*> generate_rooms(int total_rooms){
    std::vector<room*> rooms;
    std::srand(unsigned(std::time(nullptr))); //seed random
    int max = total_rooms;
    int base_x;
    int base_y;
    bool new_location;
    room* base_room;

    //make first random room
    rooms.push_back(new room(0,rand()%max,rand()%max)) ;

    for (int i = 1; i<max;i++){
        new_location = false;

        //random the position for next room
        while (!new_location){

            //random pick base room for next room
            base_room = rooms[rand()%rooms.size()];
            base_x = base_room->get_x();
            base_y = base_room->get_y();

            if (rand()%2){ //x or y
                if (rand()%2){ // + or -
                    base_x++;
                } else{
                    base_x--;
                }
            }else{
                if (rand()%2){
                    base_y++;
                } else{
                    base_y--;
                }
            }

            //if new position became out of index, rerandom
            if( base_x > max || base_x < 0 || base_y > max || base_y < 0){
                continue;
            }


            //check if position is taken
            int counter = 0;
            for(auto r : rooms){
                if(! (r->is_location(base_x,base_y))){
                    counter++;
                }
            }
            if (counter == rooms.size()){
                new_location = true;
            }
        }

        //make new room
        room* new_room = new room(i,base_x,base_y);

        //connect them
        base_room->add_edge(new_room);
        new_room->add_edge(base_room);

        //add new room to rooms vec
        rooms.push_back(new_room);

    }
    return rooms;


}

#endif //GENERATOR_GENERATOR_HPP
