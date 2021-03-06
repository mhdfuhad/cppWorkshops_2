//
//  Stringset.cpp
//  Workshop 2
//
//  Created by Mohammad Fuhad Uddin on 2021-06-06.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <fstream>
#include <utility>
#include "StringSet.h"

using namespace std;

namespace sdds{
StringSet::StringSet():count(0u), str{nullptr}{};

StringSet::StringSet(const char* fileName){
    string dummy;
    
    ifstream fin(fileName);
    while (getline(fin, dummy, ' ')) count++;
    
    str = new string[count + 1];
    fin.clear();
    fin.seekg(0, ios::beg);
    
    for (unsigned i = 0; getline(fin, str[i], ' '); i++);
};

size_t StringSet::size() const{
    return count;
};

string StringSet::operator[](size_t i) const{
    return i >= 0 && i < size() && str != nullptr ? str[i] : "";
};

StringSet::StringSet(const StringSet& obj) {
    *this = obj;
};

StringSet& StringSet::operator=(const StringSet& obj){
    if (this != &obj){
        count = obj.count;
        str = nullptr;
        delete[] str;
        if (obj.str != nullptr){
            str = new string[count];
            for(unsigned i = 0; i < count; str[i] = obj.str[i], i++);
        }
        else
            str = nullptr;
    }
    return *this;
}

StringSet::StringSet(StringSet&& obj) noexcept {
    *this = move(obj);
};

StringSet& StringSet::operator=(StringSet&& obj) noexcept{
    if (this != &obj){
        str = nullptr;
        delete[] str;
        str = obj.str;
        count = obj.count;
        obj.str = nullptr; //emptying source object
        obj.count = 0; //emptying source object
    }
    return *this;
}

StringSet::~StringSet(){
    delete[] str;
    str = nullptr;
}

}
