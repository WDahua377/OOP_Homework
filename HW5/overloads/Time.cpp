#include "Time.h"
#include <iostream>
#include <iomanip>

Time:: Time():days(0), hours(0), minutes(0), seconds(0){}
Time:: Time(int s):days(0), hours(0), minutes(0), seconds(s){
    if(s < 0){
        seconds = 0;
    }
    if(seconds >= 60){
        minutes = seconds/60;
        seconds = seconds%60;
    }

    if(minutes >= 60){
        hours = minutes/60;
        minutes = minutes%60;
    }

    if(hours >= 24){
        days = hours/24;
        hours = hours%24;
    }
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

    if(seconds >= 60){
        minutes += seconds/60;
        seconds = seconds%60;
    }

    if(minutes >= 60){
        hours += minutes/60;
        minutes = minutes%60;
    }

    if(hours >= 24){
        days += hours/24;
        hours = hours%24;
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
    if(other.seconds >= 60){
        other.minutes += other.seconds/60;
        other.seconds = other.seconds%60;
    }

    if(other.minutes >= 60){
        other.hours += other.minutes/60;
        other.minutes = other.minutes%60;
    }

    if(other.hours >= 24){
        other.days += other.hours/24;
        other.hours = other.hours%24;
    }
    return is;
}
Time Time::operator+( Time &other ) {
    days += other.days;
    hours += other.hours;
    minutes += other.minutes;
    seconds += other.seconds;
    if(days < 0 || hours < 0 || minutes < 0 || seconds < 0 ){
        days = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    if(seconds >= 60){
        minutes += seconds/60;
        seconds = seconds%60;
    }

    if(minutes >= 60){
        hours += minutes/60;
        minutes = minutes%60;
    }

    if(hours >= 24){
        days += hours/24;
        hours = hours%24;
    }
    return (*this);
}
Time Time::operator-( Time &other ) {
    while(seconds - other.seconds < 0){
        minutes -= 1;
        seconds += 60;
    }
    seconds -= other.seconds;
    while(minutes - other.minutes < 0){
        hours -= 1;
        minutes += 60;
    }
    minutes -= other.minutes;
    while(hours - other.hours < 0){
        days -= 1;
        hours += 24;
    }
    hours -= other.hours;
    days -= other.days;
    if(days < 0){
        days = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;
        return (*this);
    }
    
    if(seconds >= 60){
        minutes += seconds/60;
        seconds = seconds%60;
    }

    if(minutes >= 60){
        hours += minutes/60;
        minutes = minutes%60;
    }

    if(hours >= 24){
        days += hours/24;
        hours = hours%24;
    }
    return (*this);
}
bool Time::operator!= (const Time &other) const{
    if(days - other.days != 0 || hours - other.hours != 0 
    || minutes - other.minutes != 0 || seconds - other.seconds != 0)
        return true;
    else
        return false;
}
bool Time::operator== (const Time &other) const{
    return !(*this != other);
}
bool Time::operator>( const Time &other ) const{
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
bool Time::operator<( const Time &other ) const{
    if(*this > other || *this == other )
        return false;
    else 
        return true;
}
bool Time::operator>=( const Time &other ) const{
    if(*this > other || *this == other)
        return true;
    else
        return false;
}
bool Time::operator<=( const Time &other ) const{
    if(*this < other || *this == other)
        return true;
    else
        return false;
}
Time& Time::operator++(){
    seconds++;
    if(seconds >= 60){
        minutes += seconds/60;
        seconds = seconds%60;
    }

    if(minutes >= 60){
        hours += minutes/60;
        minutes = minutes%60;
    }

    if(hours >= 24){
        days += hours/24;
        hours = hours%24;
    }
    return *this;
}
Time Time::operator++(int){
    Time temp = *this;
    ++*this;
    if(seconds >= 60){
        minutes += seconds/60;
        seconds = seconds%60;
    }

    if(minutes >= 60){
        hours += minutes/60;
        minutes = minutes%60;
    }

    if(hours >= 24){
        days += hours/24;
        hours = hours%24;
    }
    return temp;
}
Time& Time::operator--(){
    seconds--;
    return *this;
}
Time Time::operator--(int){
    Time temp = *this;
    --*this;
    return temp;
}