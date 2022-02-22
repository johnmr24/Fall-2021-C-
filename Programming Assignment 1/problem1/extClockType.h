#pragma once
#include "clockType.h"
#include <string>
using namespace std;

class extClockType : public clockType {

public:
	extClockType();
	extClockType(int hours, int minutes, int seconds, string timeZ);
	void setTime(int hours, int minutes, int seconds, string timeZ);
	void getTime(int& hours, int& minutes, int& seconds, string& timeZ) const;
	void printTime() const;
	bool equalTime(const extClockType& otherClock) const;

private:
	string timeZone;
};
