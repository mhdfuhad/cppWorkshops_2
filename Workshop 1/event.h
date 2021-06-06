//
//  event.h
//  Workshop 1
//
//  Created by Mohammad Fuhad Uddin on 2021-05-30.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;

namespace sdds{

    class Event{
        //private members
        char* eventDesc{nullptr};
        unsigned int eventTime;
    public:
        //Required public member functions
        Event():eventDesc{ nullptr },eventTime{0} {};
        void display();
        void set(char* arr = nullptr);
        
        //Rule of three
        Event(const Event& obj);
        Event& operator=(const Event& obj);
        ~Event();
        
        //operator overload
        operator bool const();
    };

}



#endif /* Event_h */
