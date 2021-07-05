//
//  Car.cpp
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-07-04.
//

#include <string>
#include <iostream>
#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds{

Car::Car(istream& istr){
    string temp, temp2;
    getline(istr, temp, '\n');
    
    //insert maker
    temp2 = getString(temp, ',');
    m_Maker = removeSpaces(temp2);
    
    //insert condition
    temp2 = getString(temp,',');
    removeSpaces(temp2);
    m_Condition =  temp2[0];
    
    //insert top speed
    temp2 = getString(temp,'\0');
    m_TopSpeed = stod(removeSpaces(temp2));

};

double Car::topSpeed() const{
    return m_TopSpeed;
};

string Car::condition() const{
    return (m_Condition == 'n' ? "new" : (m_Condition == 'u' ? "used" : "broken"));
};

void Car::display(ostream& out) const{
    out << "| " << right << setw(10) << m_Maker << " | ";
    out << left << setw(6) << condition() << " | ";
    out << setw(6) << setprecision(2) << fixed << topSpeed() << " |";
};

string Car::removeSpaces(string& str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
};

string Car::getString(const string& str, char check){
    static unsigned long firstPos = 0u;
    static unsigned long endPos = 0u;
    unsigned long charCount = 0u;
    string extracted;
    
    endPos = str.find(check, firstPos);
    charCount = endPos - firstPos;
    extracted = str.substr(firstPos, charCount);
    firstPos = endPos + 1;
    
    return extracted;
}

}
