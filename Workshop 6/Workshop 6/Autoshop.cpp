//
//  Autoshop.cpp
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


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
        (*i)->display(out);
        out << endl;
    }
    out << "--------------------------------" << endl;
};

Autoshop::~Autoshop(){
    for(auto i = m_vehicles.begin(); i != m_vehicles.end(); i++){
        delete *i;
    }
};

}
