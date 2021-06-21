//
//  ConfirmationSender.cpp
//  Workshop 4
//
//  Created by Mohammad Fuhad Uddin on 2021-06-21.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <utility>
#include "ConfirmationSender.h"


using namespace std;
namespace sdds{

ConfirmationSender::ConfirmationSender() {};

ConfirmationSender::ConfirmationSender(const ConfirmationSender& obj){
    *this = obj;
};

ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& obj){
    if (this != &obj && obj.count > 0) {
        count = obj.count;
        delete[] m_Confirmations;
        m_Confirmations = new const Reservation*[count];
        for (size_t i = 0; i < count; i++) {
            m_Confirmations[i] = obj.m_Confirmations[i];
        }
    }
    return *this;
};

ConfirmationSender::ConfirmationSender(ConfirmationSender&& obj) noexcept {
    *this = move(obj);
};

ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& obj) noexcept {
    if (this != &obj) {
        count = obj.count;
        delete[] m_Confirmations;
        m_Confirmations = obj.m_Confirmations;
        obj.m_Confirmations = nullptr;
        obj.count = 0;
    }
    return *this;
};

ConfirmationSender::~ConfirmationSender(){
    delete[] m_Confirmations;
    m_Confirmations = nullptr;
};

ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
    bool exists = false;
    
    if(count){
        for (size_t i = 0; i < count; i++) {
            if(&res == m_Confirmations[i])
                exists = true;
        }
    }
    
    if(!exists){
        const Reservation** temp = new const Reservation*[count + 1];
        
        for(size_t i = 0; i < count; i++){
            temp[i] = m_Confirmations[i];
        }
        
        temp[count] = &res;
        delete[] m_Confirmations;
        m_Confirmations = temp;
        count += 1;
    }
    
    return *this;
};

ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
    bool exists = false;

    if (count) {
        for (size_t i = 0; i < count && !exists; i++) {
            if (&res == m_Confirmations[i]){
                exists = true;
                m_Confirmations[i] = nullptr;
            }
        }
    }

    if (exists){
        count--;
        if (!count) {
            delete[] m_Confirmations;
            m_Confirmations = nullptr;
        }
        else{
            const Reservation** tempRes = new const Reservation* [count];

            for (size_t i = 0, j = 0; j < count; i++) {
                if (m_Confirmations[i]){
                    tempRes[j] = m_Confirmations[i];
                    j++;
                };
            }
            delete[] m_Confirmations;
            m_Confirmations = tempRes;
        }
    }
    return *this;
};

ostream& operator<<(ostream& ostr, const ConfirmationSender& obj){
    ostr << "--------------------------" << endl;
    ostr << "Confirmations to Send" << endl;
    ostr << "--------------------------" << endl;
    
    if(obj.count == 0){
        ostr << "There are no confirmations to send!" << endl;
    }else{
        for (size_t i = 0; i < obj.count; i++) {
            ostr << *obj.m_Confirmations[i];
        }
    }
    ostr << "--------------------------" << endl;


    return ostr;
};

}
