//
//  SetSummable.h
//  Workshop 3
//
//  Created by Mohammad Fuhad Uddin on 2021-06-13.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include "Set.h"

#ifndef SDDS_SetSummable_h
#define SDDS_SetSummable_h

namespace sdds{

template <unsigned int N, typename T>
class SetSummable : public Set<N, T> {
public:
    T accumulate(const std::string& filter) const {
        T accumulator(filter);
        for (size_t i = 0; i < this->size(); i++) {
            if (accumulator.isCompatibleWith(this->get(i))){
                accumulator += this->get(i);
            }
        }
        return accumulator;
    };
};
}

#endif /* SetSummable_h */
