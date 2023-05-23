#include "Point.hpp"
#include <string> 
#include <cmath>
#include <iostream>
using namespace ariel;
using namespace std; 

Point :: Point(){
    this->X_aixes = 0;
    this->Y_aixes =0;
}

Point :: Point( double x ,double y){
    this->X_aixes = x; 
    this->Y_aixes =y; 
}

double Point :: getX(){
    return this->X_aixes;
}

double Point :: getY(){
    return this->Y_aixes;
}

double Point::distance(const Point &other) {
  return sqrt(pow(X_aixes - other.X_aixes, 2) + pow(Y_aixes - other.Y_aixes, 2));
}

string Point :: print (){
    return "("+ to_string(this->X_aixes)+ ","+ to_string(this->Y_aixes)+")";
}

Point Point:: moveTowards (Point source ,Point desten , double distance ) {
    double dit = source.distance(desten);
    if (distance < 0){
        throw invalid_argument("distance must be over zero!");
    }
    if (distance == 0){
        return source;
    }
    if(dit <= distance){
        return desten;
    }
    else{
    double px = desten.X_aixes - source.X_aixes;
    double py = desten.Y_aixes - source.Y_aixes;
    double m = distance / dit; 
        return Point(source.X_aixes + m * px, source.Y_aixes + m * py);
    } 
}

