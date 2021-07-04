//
//  Autoshop.h
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-07-04.
//

#ifndef Autoshop_h
#define Autoshop_h

#include <vector>
#include "Vehicle.h"

namespace sdds{

class Autoshop{
    std::vector<Vehicle*> m_vehicles;
public:
    Autoshop& operator +=(Vehicle* theVehicle);
    void display(std::ostream& out) const;
};

}

#endif /* Autoshop_h */
