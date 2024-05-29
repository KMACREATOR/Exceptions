#pragma once

#include <iostream>
#include <string>


#ifndef TIME_H
#define TIME_H

#endif // TIME_H

class Incorrect_Time : public std::out_of_range {
private:
    int hour, minute, second;
public:

    Incorrect_Time(int h, int m, int s) : std::out_of_range("!!!INCORRECT TIME INPUT!!!"), hour(h), minute(m), second(s) {}

    void printIncorrectTime();
};


void Incorrect_Time::printIncorrectTime() {
    std::cout << "Incorrect Time: " << hour << " hours " << minute << " minutes " << second << " seconds.\n";
}

class Time {
private:
    int hour, minute, second;
public:
    Time(int h, int m, int s);
    bool isCorrectTime();
    void printTime();
};


Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {
    if (!Time::isCorrectTime()) {
        throw Incorrect_Time(h, m, s);
    }
}


void Time::printTime() {
    std::cout << "Time: " << hour << " hours " << minute << " minutes " << second << " seconds.\n";
}

bool Time::isCorrectTime() {
    return((hour >=0 && hour < 24) && (minute >= 0 && minute < 60) && (second >=0 && second < 60));
}
