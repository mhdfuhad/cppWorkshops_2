//
//  Racecar.h
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_Racecar_h
#define SDDS_Racecar_h

#include "Car.h"

namespace sdds{

class Racecar : public Car {
    double m_booster{};
public:
    Racecar(std::istream& in);
    void display(std::ostream& out) const;
    double topSpeed() const;
};


}

#endif /* Racecar_h */
