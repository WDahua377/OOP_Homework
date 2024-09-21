#include "Time.h"
#include <iostream>
#include <iomanip>

Time:: Time():days(0), hours(0), minutes(0), seconds(0){}
Time:: Time(int s):days(0), hours(0), minutes(0), seconds(s){
    if(s < 0){
        seconds = 0;
    }
    normalize();
}


Time:: Time(int d,int h, int m, int s){
    if(d < 0 || h < 0 || m < 0 || s < 0 ){
        days = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    else{
        days = d;
        hours = h;
        minutes = m;
        seconds = s;
    }

    normalize();
}


void Time::normalize(){
    if(seconds >= 60) {
        minutes += seconds / 60;
        seconds = seconds % 60;
    }
    if(minutes >= 60) {
        hours += minutes / 60;
        minutes = minutes % 60;
    }
    if(hours >= 24) {
        days += hours / 24;
        hours = hours % 24;
    }

    if(seconds < 0){
        minutes -= 1;
        seconds += 60;
    }
    if(minutes < 0){
        hours -= 1;
        minutes += 60;
    }
    if(hours < 0){
        days -= 1;
        hours += 24;
    }
}


std::ostream &operator<<(std::ostream& os, const Time& other){
    os << other.days << std::setfill('0') << "~" << std::setw(2) 
    <<  std::setw(2) << other.hours << ":" <<  std::setw(2) 
    << other.minutes << ":" <<  std::setw(2) << other.seconds << std::endl;
    return os;
}


std::istream &operator>>(std::istream& is, Time& other){
    char tilde = '~', colon = ':';
    is >> other.days >> tilde >> other.hours >> colon >> other.minutes >> colon >> other.seconds;
    if(other.days < 0 || other.hours < 0 || other.minutes < 0 || other.seconds < 0 ){
        other.days = 0;
        other.hours = 0;
        other.minutes = 0;
        other.seconds = 0;
    }

    other.normalize();
    return is;
}


Time Time::operator+(Time &other){
    days += other.days;
    hours += other.hours;
    minutes += other.minutes;
    seconds += other.seconds;

    normalize();

    if(days < 0 || hours < 0 || minutes < 0 || seconds < 0 ){
        days = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    return (*this);
}


Time Time::operator-(Time &other){
    seconds -= other.seconds;
    minutes -= other.minutes;
    hours -= other.hours;
    days -= other.days;

    // not allow to be negative
    if(days < 0){
        days = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;
        return (*this);
    }
    
    normalize();
    return (*this);
}


bool Time::operator!=(const Time &other) const{
    if(days - other.days != 0 || hours - other.hours != 0 
    || minutes - other.minutes != 0 || seconds - other.seconds != 0)
        return true;
    else
        return false;
}


bool Time::operator==(const Time &other) const{
    return !(*this != other);
}


bool Time::operator>(const Time &other) const{
    if(days > other.days)
        return true;
    else if(days == other.days){
        if(hours > other.hours)
            return true;
        else if(hours == other.hours){
            if(minutes > other.minutes)
                return true;
            else if(minutes == other.minutes){
                if(seconds > other.seconds)
                    return true;
                else
                    return false;
            }
        }
    }
    return false;
}


bool Time::operator<(const Time &other) const{
    if(*this > other || *this == other )
        return false;
    else 
        return true;
}


bool Time::operator>=(const Time &other) const{
    if(*this > other || *this == other)
        return true;
    else
        return false;
}


bool Time::operator<=(const Time &other) const{
    if(*this < other || *this == other)
        return true;
    else
        return false;
}

// Prefix increment operator.
Time& Time::operator++(){
    seconds++;

    normalize();
    return *this;
}

// Postfix increment operator.
Time Time::operator++(int){
    Time temp = *this;
    ++(*this);
    normalize();
    return temp;
}

// Prefix increment operator.
Time& Time::operator--(){
    seconds--;
    return *this;
}

// Postfix increment operator.
Time Time::operator--(int){
    Time temp = *this;
    --(*this);
    return temp;
}
