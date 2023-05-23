#include "Cowboy.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace ariel; 


Cowboy :: Cowboy (string name, const Point &location):Character(name, location, 110),bullets(6){}

int Cowboy :: getBullets() const{
    return this->bullets;
}

void Cowboy::shoot(Character *enemy) {
  if (!isAlive())
    throw runtime_error("Cowboy is not alive");
  if (!enemy->isAlive())
    throw runtime_error("Enemy is not alive");
  if (this == enemy)
    throw runtime_error("Cannot attack itself");
  if (hasboolets()) {
    enemy->hit(10);
    bullets -= 1;
  }
}

bool Cowboy :: hasboolets()const {
return bullets>0;
}

void Cowboy :: reload(){
    if(!(this->isAlive())){
        __throw_runtime_error("owboy is dead");
    }
    this->bullets=6; 
}

void Cowboy :: action(Character *enemy){
  if (!isAlive() || !enemy->isAlive())
    return;
  if (hasboolets())
    shoot(enemy);
  else
    reload();
}
