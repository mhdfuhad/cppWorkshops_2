//
//  Reservation.cpp
//  Workshop 4
//
//  Created by Mohammad Fuhad Uddin on 2021-06-21.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <string>
#include <iomanip>
#include <iostream>
#include "Reservation.h"

using namespace std;

namespace sdds{

Reservation::Reservation() {};

Reservation::Reservation(const string& res){
    string temp;
    
    //insert ID
    temp = getString(res, ':');
    resID = removeSpaces(temp);
    
    //insert Name
    temp = getString(res, ',');
    resName = removeSpaces(temp);
    
    //insert Email
    temp = getString(res,',');
    resEmail = removeSpaces(temp);
    
    //insert party size
    temp = getString(res,',');
    resCount = stoi(removeSpaces(temp));
    
    //insert day of reservation
    temp = getString(res,',');
    resDay = stoi(removeSpaces(temp));
    
    //insert hour of reservation
    temp = getString(res,'\0');
    resHour = stoi(removeSpaces(temp));
};

string Reservation::removeSpaces(string& str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
};

string Reservation::getString(const string& str, char check){
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

ostream& operator<<(ostream& ostr, const Reservation& obj){
    string email = "<" + obj.resEmail + ">";
    
    ostr << "Reservation " << setw(10) << right << obj.resID << ": " ;
    ostr << setw(20) << right << obj.resName << "  ";
    ostr << setw(24) << left << email;
    
    if(obj.resHour >= 6 && obj.resHour <= 9){
        ostr << "Breakfast on day ";
    }else if (obj.resHour >= 11 && obj.resHour <= 15){
        ostr << "Lunch on day ";
    }else if (obj.resHour >= 17 && obj.resHour <= 21){
        ostr << "Dinner on day ";
    }else{
        ostr << "Drinks on day ";
    }
    
    ostr <<  obj.resDay << " @ " << obj.resHour << ":00 for ";
    ostr << obj.resCount << (obj.resCount > 1 ? " people." : " person.") << endl;
    
    return ostr;
};


}
