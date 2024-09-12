class Cube{
    
    private:
    double x,y,z;

    public:
    double operator/( Cube &other );
    bool operator!=( Cube &other );
    //Cube(double a, double b, double c):x(a), y(b), z(c){}
};