#pragma once

class clockType {

public:

	clockType(int hours, int minutes, int seconds);
	clockType();
	void setTime(int hours, int minutes, int seconds);
	void getTime(int& hours, int& minutes, int& seconds) const;
	void printTime() const; 
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	bool equalTime(const clockType& otherClock) const;

private:
	int hr, min, sec;
};
