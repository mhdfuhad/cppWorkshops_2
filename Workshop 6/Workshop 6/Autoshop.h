//
//  Autoshop.h
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef Autoshop_h
#define Autoshop_h

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds{

class Autoshop{
    std::vector<Vehicle*> m_vehicles;
public:
    Autoshop& operator +=(Vehicle* theVehicle);
    void display(std::ostream& out) const;
    template<typename T>
    void select(T test, std::list<const Vehicle*>& vehicles){
        std::vector<Vehicle*>::iterator i;
        for(i = m_vehicles.begin(); i != m_vehicles.end(); i++)
            if(test(*i))
                vehicles.push_back(*i);
    };
    ~Autoshop();
};

}

#endif /* Autoshop_h */
