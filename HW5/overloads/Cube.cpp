#include "Cube.h"
#include <iostream>

double Cube::operator/ (Cube &other){
    return (x+y+z) / (other.x+other.y+other.z);
}

bool Cube::operator!= (Cube &other){
    double epsilon = 0.00001;
    return (x*y*z) - (other.x*other.y*other.z) > epsilon;
}