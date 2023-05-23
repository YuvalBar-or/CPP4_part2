#pragma once
#include "Character.hpp"
#include <string>
namespace ariel{};

class Ninja: public Character{
    private:
        int speed;
    
    public:
        Ninja() = delete; 
        Ninja (string name ,const Point &location, int lives, int speed);
        void move(Character *enemy);
        void slash(Character *enemy) ;
        void action(Character *enemy) override;
        int getspeed();

};


