//
//  Reservation.h
//  Workshop 4
//
//  Created by Mohammad Fuhad Uddin on 2021-06-21.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_Reservation_h
#define SDDS_Reservation_h

#include <string>
#include <iostream>

namespace sdds {

class Reservation{
    std::string resID{'\0'};
    std::string resName{'\0'};
    std::string resEmail{'\0'};
    unsigned int resCount{0u};
    unsigned int resDay{0u};
    unsigned int resHour{0u};
    std::string removeSpaces(std::string& str);
    std::string getString(const std::string& str, char check = '\0');
public:
    Reservation();
    Reservation(const std::string& res);
    friend std::ostream& operator<<(std::ostream& ostr, const Reservation& obj);
};


}

#endif /* SDDS_Reservation_h */
