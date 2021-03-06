//
//  Car.h
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef Car_h
#define Car_h

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds{

class Car : public Vehicle {
    std::string m_Maker{};
    char m_Condition{};
    double m_TopSpeed{0};
public:
    Car(std::istream& in);
    double topSpeed() const;
    std::string condition() const;
    void display(std::ostream& out) const;
};

}
#endif /* Car_h */
