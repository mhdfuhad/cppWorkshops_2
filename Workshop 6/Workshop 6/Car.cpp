//
//  Car.cpp
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Car.h"
#include "Utilities.h"

using namespace std;
namespace sdds{

Car::Car(istream& in){
    string temp;

    //insert maker
    getline(in, temp, ',');
    temp = getString(temp, ',');
    m_Maker = removeSpaces(temp);
    
    //insert condition
    getline(in, temp, ',');
    temp = getString(temp,',');
    removeSpaces(temp);
    if(empty(temp))
        m_Condition = 'n';
    else if(temp[0] != 'n' && temp[0] != 'b' && temp[0] != 'u'){
        getline(in, temp, '\n');
        throw string("Invalid record!");
    }
    else
        m_Condition =  temp[0];
    
    //insert top speed
    bool found = false;
    temp = "";
    char data = '\0';
    for(int i = 0; !found; i++){
        in.get(data);
        if(data == ',' || data == '\n' || !in){ //to stop at a comma allowing to getline until '\n' in racecar module
            found = true;
            if(!in)
                data = '\0'; //for last record of the file
        }
        if(!found)
            temp += data;
    }
    temp = getString(temp, data);
    removeSpaces(temp);
    if(isNan(temp)){
        getline(in, temp, '\n');
        throw string("Invalid record!");
    }
    else
        m_TopSpeed = stod(temp);
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

}
