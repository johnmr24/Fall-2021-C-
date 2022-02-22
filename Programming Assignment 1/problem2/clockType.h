#pragma once
#include <iostream>
using namespace std;

class clockType {

    friend ostream& operator <<(ostream& output, const clockType& clock);

public:

    clockType(int hours, int minutes, int seconds);
    clockType();
    void setTime(int hours, int minutes, int seconds);
    void getTime(int& hours, int& minutes, int& seconds) const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    clockType operator +(const clockType& otherClock);
    bool operator ==(const clockType& otherClock);


private:
    int hr, min, sec;
};
