#pragma once
namespace ariel {};
#include "Point.hpp"
#include <string>
using namespace std;

class Character{
    
    private: 
        Point location;
        int lives;
        string name; 
        bool inGame=false; 

    public: 
        Character() = delete;
        Character(string name, const Point &place , int lives);
        Character(const Character &other);
        Character(Character &&other) noexcept;
        bool isAlive() const; 
        virtual double distance (Character *other);
        void hit (int number);
        string getName();
        Point getLocation();
        virtual string print();
        int getLives();
        virtual void setLocation(Point newLocation); 
        virtual void setINGAME();
        virtual bool getINGAME();
        virtual void action(Character *enemy) = 0;
        Character &operator=(const Character &other);
        Character &operator=(Character &&other) noexcept;
       virtual ~Character();
      
        
        bool getInTeam()const{
            return this->inGame;
        }
        void setInTeam(bool flag){
            this->inGame = flag;
        }

       

};