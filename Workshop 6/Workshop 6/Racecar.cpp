//
//  Racecar.cpp
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <string>
#include <sstream>
#include "Racecar.h"
#include "Utilities.h"

using namespace std;
namespace sdds{

Racecar::Racecar(std::istream& in): Car(in) {
    string temp;
    getline(in, temp, '\n');
    
    //insert booster
    temp = getString(temp, '\n');
    removeSpaces(temp);
    m_booster = stod(temp);
};
void Racecar::display(std::ostream& out) const{
    Car::display(out);
    out << "*";
};

double Racecar::topSpeed() const{
    return Car::topSpeed() * (1 + m_booster);
};


}
