#include <ostream>
class Time{

    friend std::istream &operator>>(std::istream& is, Time& other);
    friend std::ostream &operator<<(std::ostream& os, const Time& other);

    private:
    int days;
    int hours;
    int minutes;
    int seconds;

    public:
    Time();
    Time(int s);
    Time(int d,int h, int m, int s);
    // void display() const;
    void Time::normalize();
    Time operator+( Time &other );
    Time operator-( Time &other );
    bool operator!=( const Time &other ) const;
    bool operator==( const Time &other ) const;
    bool operator>=( const Time &other ) const;
    bool operator<=( const Time &other ) const;
    bool operator>( const Time &other ) const;
    bool operator<( const Time &other ) const;
    Time& operator++();       // Prefix increment operator.
    Time operator++(int);     // Postfix increment operator.
    Time& operator--();       // Prefix decrement operator.
    Time operator--(int);     // Postfix decrement operator.
}; 