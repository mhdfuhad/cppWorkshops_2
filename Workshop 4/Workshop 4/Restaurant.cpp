//
//  Restaurant.cpp
//  Workshop 4
//
//  Created by Mohammad Fuhad Uddin on 2021-06-21.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <utility>
#include "Restaurant.h"

using namespace std;
namespace sdds{

Restaurant::Restaurant(const Reservation* reservations[], size_t cnt){
    count = cnt;
    delete[] m_Reservations;
    m_Reservations = new Reservation[count];
    for (size_t i = 0; i < count; i++) {
        m_Reservations[i] = *reservations[i];
    }
};

Restaurant::Restaurant(const Restaurant& obj){
    *this = obj;
};

Restaurant& Restaurant::operator=(const Restaurant& obj){
    if (this != &obj && obj.count > 0) {
        count = obj.count;
        delete[] m_Reservations;
        m_Reservations = new Reservation[count];
        for (size_t i = 0; i < count; i++) {
            m_Reservations[i] = obj.m_Reservations[i];
        }
    }
    return *this;
};

Restaurant::Restaurant(Restaurant&& obj){
    *this = move(obj);
};

Restaurant& Restaurant::operator=(Restaurant&& obj){
    if (this != &obj) {
        count = obj.count;
        delete[] m_Reservations;
        m_Reservations = obj.m_Reservations;
        obj.m_Reservations = nullptr;
        obj.count = 0;
    }
    return *this;
};

Restaurant::~Restaurant(){
    delete[] m_Reservations;
    m_Reservations = nullptr;
};

size_t Restaurant::size() const{
    return count;
};

ostream& operator<<(ostream& ostr, const Restaurant& obj){
    static size_t call_count = 1;
    
    ostr << "--------------------------" << endl;
    ostr << "Fancy Restaurant (" << call_count << ")" << endl;
    ostr << "--------------------------" << endl;
    
    if(obj.size() == 0){
        ostr << "This restaurant is empty!" << endl;
    }else{
        for (size_t i = 0; i < obj.size(); i++) {
            ostr << obj.m_Reservations[i];
        }
    }
    ostr << "--------------------------" << endl;
    call_count++;

    return ostr;
};


}
