//
//  PairSummable.h
//  Workshop 3
//
//  Created by Mohammad Fuhad Uddin on 2021-06-13.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include "Pair.h"

#ifndef SDDS_PairSummable_h
#define SDDS_PairSummable_h

namespace sdds{

template<typename V, typename K>
class PairSummable : public Pair<V, K> {
    static V init;
    static size_t fieldWidth;
public:
    PairSummable() {};
    PairSummable(const K& key, const V& value = init):Pair<V,K>(key,value){
        if(key.size() > fieldWidth){
            fieldWidth = key.size();
        }
    };
    bool isCompatibleWith(const PairSummable<V, K>& b) const{
        return b.key() == this->key();
    };
    PairSummable<V, K>& operator+=(const PairSummable<V, K>& obj){
        *this = PairSummable(this->key(), this->value() + obj.value());
        return *this;
    }
    void display(std::ostream& os) const{
        os.setf(std::ios::left);
        os.width(fieldWidth);
        Pair<V,K>::display(os);
        os.unsetf(std::ios::left);
    };
};

template<typename V, typename K>
 V PairSummable<V, K>::init{};
template<typename V, typename K>
 size_t PairSummable<V, K>::fieldWidth{0};

template<>
PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& obj){
    
    std::string str;
    if(this->value().empty()){
        str = obj.value();
    }else{
        str = this->value() + ", " + obj.value();
    }
    *this = PairSummable(this->key(), str);
    
    return *this;
}

}
#endif /* PairSummable_h */
