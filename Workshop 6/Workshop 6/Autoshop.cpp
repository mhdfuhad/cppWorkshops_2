//
//  Autoshop.cpp
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-07-04.
//

#include <vector>
#include "Autoshop.h"

using namespace std;
namespace sdds{

Autoshop& Autoshop::operator+=(Vehicle* theVehicle){
    m_vehicles.push_back(theVehicle);
    return *this;
};

void Autoshop::display(ostream& out) const{
    out << "--------------------------------" << endl;
    out << "| Cars in the autoshop!        |" << endl;
    out << "--------------------------------" << endl;
    for(auto i = m_vehicles.begin(); i != m_vehicles.end(); i++){
        out << *i.display() << endl;
    }
    out << "--------------------------------" << endl;
};

}
