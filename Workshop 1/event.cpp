//
//  event.cpp
//  Workshop 1
//
//  Created by Mohammad Fuhad Uddin on 2021-05-30.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

using namespace std;

unsigned int g_sysClock = 0;

namespace sdds{

Event::operator bool const(){
    return eventDesc != nullptr && eventDesc[0] != '\0';
};

void Event::display(){
    static unsigned int counter = 0;
    cout << setw(2) << counter + 1 << ". ";
    
    if(*this){
        unsigned int H = (eventTime/60)/60;
        unsigned int M = (eventTime - ((H * 60) * 60))/60;
        unsigned int S = eventTime - (((H * 60) * 60) + M * 60);
        
        cout << setw(2) << setfill('0') << H << ":" << setw(2) << M << ":" << setw(2) << S << " => " << eventDesc << setfill(' ') << endl;
    }
    else{
        cout << "| No Event |" << endl;
    }
    counter++;
}

void Event::set(char* arr){
    if(arr != nullptr && arr[0] != '\0'){
        delete[] eventDesc;
        eventDesc = new char[strlen(arr) + 1];
        strcpy(eventDesc, arr);
        eventTime = g_sysClock;
    }else{
        eventTime = 0;
        eventDesc = nullptr;
    }
}

Event::Event(const Event& obj) {
        *this = obj;
}

Event& Event::operator=(const Event& obj) {
    if (this != &obj) {
        if (obj.eventDesc != nullptr && obj.eventDesc[0] != '\0') {
            delete[] eventDesc;
            eventDesc = new char[strlen(obj.eventDesc) + 1];
            strcpy(eventDesc, obj.eventDesc);
            eventTime = obj.eventTime;
        }
        else {
            eventTime = 0;
            eventDesc = nullptr;
        }
    }
    return *this;
}

Event::~Event() {
    delete[] eventDesc;
    eventDesc = nullptr;
}

}
