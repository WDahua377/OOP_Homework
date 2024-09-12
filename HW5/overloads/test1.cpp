#include <iostream>
#include "Cube.h"
#include "Time.h"

using namespace std;

int main(){
    Time z(1,12,15,57),x(1,12,15,58);
    //cin >> z >> x;
    //z = z-x;
    cout << ++z << endl;
    cout << x << endl;
    if(z >= x)
        cout << ">=" << endl;
    if(z <= x)
        cout << "<=" << endl;
    if(z > x)
        cout << ">" << endl;
    if(z < x)
        cout << "<" << endl;
    if(z == x) 
        cout << "==" << endl;
    if(z != x)
        cout << "!=" <<  endl;
    //z.display();
    int a;



    //Cube a{0.2, 2.0, 4.5};
    //Cube b{0.3, 0.6, 10.0};
    //double c = a/b;
    //if(a != b){
        //cout << "a != b" << endl;
    //}
    //cout << c << endl;
}