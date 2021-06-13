//
//  Set.h
//  Workshop 3
//
//  Created by Mohammad Fuhad Uddin on 2021-06-13.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>

#ifndef SDDS_Set_H
#define SDDS_Set_H

namespace sdds{

template <unsigned int N, typename T>
class Set{
    T arr[N]{};
    unsigned elementCount{0u};
public:
    size_t size() const{
        return elementCount;
    };
    const T& get(size_t idx) const{
        return arr[idx];
    };
    void operator+=(const T& item){
        if (elementCount < N) {
            arr[elementCount] = item;
            elementCount++;
        }
    };
};

}

#endif /* Set_H */
