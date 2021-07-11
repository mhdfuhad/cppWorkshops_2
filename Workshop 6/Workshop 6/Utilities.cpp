//
//  Utilities.cpp
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;

namespace sdds{

Vehicle* createInstance(istream& in){
    Vehicle* temp = nullptr;
    string m_Type, dummy;
    getline(in, m_Type, ',');
    removeSpaces(m_Type);
    
    if (m_Type[0] == 'c' || m_Type[0] == 'C'){
        temp = new Car(in);
        return temp;
    }else if(m_Type[0] == 'r' || m_Type[0] == 'R'){
        temp = new Racecar(in);
        return temp;
    }
    else if(m_Type.empty()){
        return temp;
    }
    else{
        getline(in, dummy, '\n');
        throw string("Unrecognized record type: [") + m_Type[0] + ']';
    }
};

string removeSpaces(string& str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
};

string getString(const string& str, char check){
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

bool empty(string str){
    for(long unsigned int i = 0; i < str.length(); i++){
        if(!isspace(str[i]) || !str.empty())
            return false;
    }
    return true;
}

bool isNan(string str){
    bool Nan = false;
    for(long unsigned int i = 0; i < str.length() && !Nan; i++){
        if(!isdigit(str[i]))
            Nan = true;
    };
    return Nan;
}

}
