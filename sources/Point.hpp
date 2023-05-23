#pragma once
#include <string>
using namespace std;
namespace ariel {}; 

class Point { 
    private:
    double X_aixes,Y_aixes; 

    public:
    Point();
    double getX();
    double getY();
    Point (double X_aixes, double Y_aixes);
    double distance (const Point &point);
    string print (); 
    static Point moveTowards (Point source ,Point desten , double distance );

};