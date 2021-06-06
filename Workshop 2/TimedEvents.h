//
//  TimedEvents.hpp
//  Workshop 2
//
//  Created by Mohammad Fuhad Uddin on 2021-06-06.
//

#ifndef sdds_TimedEvents_h
#define sdds_TimedEvents_h

#include <chrono>
#include <iostream>

namespace sdds {

class TimedEvents{
    unsigned noOfRecords{0u};
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    struct Events{
        std::string eventName;
        std::string unitTime;
        std::chrono::steady_clock::duration eventDuration;
    }Events[10];
public:
    static unsigned eventCount;
    TimedEvents();
    void startClock();
    void stopClock();
    void addEvent(const char* str);
    friend std::ostream& operator<<(std::ostream& ostr, const TimedEvents& obj);
};

}

#endif /* TimedEvents_h */
