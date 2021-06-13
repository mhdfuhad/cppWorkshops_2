//
//  Pair.h
//  Workshop 3
//
//  Created by Mohammad Fuhad Uddin on 2021-06-13.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

namespace sdds{

template<typename V, typename K>
class Pair{
    V pairValue{};
    K pairKey{};
public:
    Pair(){};
    Pair(const K& key, const V& value){
        pairKey = key;
        pairValue = value;
    };
    const V& value() const{
        return pairValue;
    };
    const K& key() const{
        return pairKey;
    };
    virtual void display(std::ostream& os) const{
        os << pairKey << " : " << pairValue << std::endl;
    };
};

template<typename V, typename K>
std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair){
    pair.display(os);
    return os;
};

}

#endif /* PAIR_H */
