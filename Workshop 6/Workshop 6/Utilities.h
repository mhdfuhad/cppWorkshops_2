//
//  Utilities.h
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef Utilities_h
#define Utilities_h

#include <string>
#include "Vehicle.h"

namespace sdds{
    Vehicle* createInstance(std::istream& in);
    std::string removeSpaces(std::string& str);
    std::string getString(const std::string& str, char check);
    bool empty(std::string str);
    bool isNan(std::string str);
}

#endif /* Utilities_h */
