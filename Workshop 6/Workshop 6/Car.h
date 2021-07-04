//
//  Car.h
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-07-04.
//

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
    std::string removeSpaces(std::string& str);
    std::string getString(const std::string& str, char check);
public:
    Car(std::istream& istr);
    double topSpeed() const;
    std::string condition() const;
    void display(std::ostream& out) const;
};

}
#endif /* Car_h */
