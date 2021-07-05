//
//  Utilities.h
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-07-04.
//

#ifndef Utilities_h
#define Utilities_h

#include <string>
#include "Vehicle.h"
#include "Car.h"

namespace sdds{
std::string removeSpaces(std::string& str);
Vehicle* createInstance(std::istream& in);
}

#endif /* Utilities_h */
