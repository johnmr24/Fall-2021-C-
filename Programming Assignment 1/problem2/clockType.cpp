#include "clockType.h"
#include <iostream>
using namespace std;

//sets the time of a clock object
void clockType::setTime(int hours, int minutes, int seconds) {

    if (0 <= hours && hours < 24) {
        hr = hours;
    }
    else {
        hr = 0;
    }

    if (0 <= minutes && minutes < 60) {
        min = minutes;
    }
    else {
        min = 0;
    }

    if (0 <= seconds && seconds < 60) {
        sec = seconds;
    }
    else {
        sec = 0;
    }

}

//gets the time of a clock object
void clockType::getTime(int& hours, int& minutes, int& seconds) const {

    hours = hr;
    minutes = min;
    seconds = sec;
}

//increments the hours by one of a clock object
void clockType::incrementHours() {

    hr++;
    while (hr > 23) {
        hr = hr - 24;
    }
}

//increments the minutes by one of a clock object
void clockType::incrementMinutes() {

    min++;
    while (min > 59) {
        min = min - 60;
        incrementHours();
    }
}

//increments the seconds by one of a clock object
void clockType::incrementSeconds() {

    sec++;
    while (sec > 59) {
        sec = sec - 60;
        incrementMinutes();
    }
}

//default constructor with no parameters
clockType::clockType() {

    hr = 0;
    min = 0;
    sec = 0;
}

//default constructor with parameters
clockType::clockType(int hours, int minutes, int seconds) {

    setTime(hours, minutes, seconds);
}

//overloaded + operator to add two clock objects
clockType clockType::operator +(const clockType& otherClock) {

    clockType temp;

    temp.hr = hr + otherClock.hr;
    if (temp.hr > 23) {
        temp.incrementHours();
    }
    temp.min = min + otherClock.min;
    if (temp.min > 59) {
        temp.incrementMinutes();
    }
    temp.sec = sec + otherClock.sec;
    if (temp.sec > 59) {
        temp.incrementSeconds();
    }

    return temp;
}

//overloaded == operator to compare two clock objects for equality
bool clockType::operator==(const clockType& otherClock) {

    if ( (hr == otherClock.hr) && (min == otherClock.min) && (sec == otherClock.sec) ) {
        return true;
    }

    else {
        return false;
    }
}

//overloaded << operator to output a clock object using cout
ostream& operator<<(ostream& output, const clockType& clock) {

    output << clock.hr << ":" << clock.min << ":" << clock.sec << endl;

    return output;
}

