#include <iostream>
#include "Grid.h"

using namespace std;

int main() {
    Grid a;
    for(int i = 0; i < 5; i++){
        a.Grow(2,3);
        a.Grow(3,2);
        a.Display();
    }
    return 0;
}
