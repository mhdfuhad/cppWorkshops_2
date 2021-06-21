//
//  Restaurant.h
//  Workshop 4
//
//  Created by Mohammad Fuhad Uddin on 2021-06-21.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_Restaurant_h
#define SDDS_Restaurant_h

#include <iostream>
#include "Reservation.h"

namespace sdds {

class Restaurant{
    size_t count{0};
    Reservation* m_Reservations{nullptr};
public:
    Restaurant(const Reservation* reservations[], size_t cnt);
    Restaurant(const Restaurant& obj);
    Restaurant& operator=(const Restaurant& obj);
    Restaurant(Restaurant&& obj);
    Restaurant& operator=(Restaurant&& obj);
    ~Restaurant();
    std::size_t size() const;
    friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& obj);
};

}

#endif /* SDDS_Restaurant_h */
