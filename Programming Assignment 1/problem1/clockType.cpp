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
void clockType::getTime(int& hours, int& minutes, int& seconds) const{

	hours = hr;
	minutes = min;
	seconds = sec;
}

//prints the time of a clock object
void clockType::printTime() const {

	if (hr < 10) {
		cout << "0";
	}
	cout << hr << ":";

	if (min < 10) {
		cout << "0";
	}
	cout << min << ":";

	if (sec < 10) {
		cout << "0";
	}
	cout << sec;
}

//increments the hours by one
void clockType::incrementHours() {

	hr++;
	if (hr > 23) {
		hr = 0;
	}
}

//increments the minutes by one
void clockType::incrementMinutes() {

	min++;
	if (min > 59) {
		min = 0;
		incrementHours();
	}
}

//increments the seconds by one
void clockType::incrementSeconds() {

	sec++;
	if (sec > 59) {
		sec = 0;
		incrementMinutes();
	}
}

//compares two clock objects for equality
bool clockType::equalTime(const clockType& otherClock) const {

	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

//default constructor with no parameters
clockType::clockType() {

	hr = 0;
	min = 0;
	sec = 0;
}

//deafult constructor with parameters
clockType::clockType(int hours, int minutes, int seconds){

	setTime(hours, minutes, seconds);
}


