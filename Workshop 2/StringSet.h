//
//  Stringset.h
//  Workshop 2
//
//  Created by Mohammad Fuhad Uddin on 2021-06-06.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef sdds_StringSet_h
#define sdds_StringSet_h

#include <string>
#include <utility>

namespace sdds{

class StringSet{
    size_t count{0};
    std::string* str;
public:
    //constructors
    StringSet();
    StringSet(const char* fileName);
    //query members
    size_t size() const;
    std::string operator[](size_t i) const;
    //copy constructor and copy assignment operator
    StringSet(const StringSet& obj);
    StringSet& operator=(const StringSet& obj);
    //move constructor and move assignment operator
    StringSet(StringSet&& obj) noexcept;
    StringSet& operator=(StringSet&& obj) noexcept;
    //destructor
    ~StringSet();
};

}

#endif /* StringSet_h */
