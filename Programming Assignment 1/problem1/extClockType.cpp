#include "extClockType.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor with no parameters
extClockType::extClockType()
	:clockType()
{
	timeZone = "";
}

//default constructor with parameters
extClockType::extClockType(int hours, int minutes, int seconds, string timeZ)
	: clockType(hours, minutes, seconds)
{
	timeZone = timeZ;
}

//sets the time of the ext clock object
void extClockType::setTime(int hours, int minutes, int seconds, string timeZ) {

	clockType::setTime(hours, minutes, seconds);
	timeZone = timeZ;
}

//gets the time of the ext clock object
void extClockType::getTime(int& hours, int& minutes, int& seconds, string& timeZ) const{

	clockType::getTime(hours, minutes, seconds);
	timeZ = timeZone;
}

//prints the time of the  ext clock, hours minutes seconds and time zone
void extClockType::printTime() const{

	clockType::printTime();
	cout << " " << timeZone;
}

//compares two ext clock objects for equality
bool extClockType::equalTime(const extClockType& otherClock) const {

	return (clockType::equalTime(otherClock) && timeZone == otherClock.timeZone);
}
