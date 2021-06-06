//
//  TimedEvents.cpp
//  Workshop 2
//
//  Created by Mohammad Fuhad Uddin on 2021-06-06.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace sdds{

unsigned TimedEvents::noOfRecords{0u};

TimedEvents::TimedEvents(){};

void TimedEvents::startClock(){
    startTime = chrono::steady_clock::now();
};

void TimedEvents::stopClock(){
    endTime = chrono::steady_clock::now();
};

void TimedEvents::addEvent(const char* str){
    Events[noOfRecords].eventName = str;
    Events[noOfRecords].unitTime = "nanoseconds";
    Events[noOfRecords].eventDuration = chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    noOfRecords++;
};

ostream& operator<<(ostream& ostr, const TimedEvents& obj){
    ostr << "--------------------------" << '\n' << "Execution Times:" << '\n' << "--------------------------" << endl;
    for (unsigned i = 0; i < TimedEvents::noOfRecords; i++){
        ostr << setw(21) << setiosflags(ios::left) << obj.Events[i].eventName <<
        " " << setw(13) << setiosflags(ios::right) << obj.Events[i].eventDuration.count() <<
        " " << obj.Events[i].unitTime << resetiosflags(ios::right) << endl;
    }
    ostr << "--------------------------" << endl;
    return ostr;
};

}
