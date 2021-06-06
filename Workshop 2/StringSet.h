//
//  Stringset.hpp
//  Workshop 2
//
//  Created by Mohammad Fuhad Uddin on 2021-06-06.
//

#ifndef sdds_StringSet_h
#define sdds_StringSet_h

#include <string>
#include <utility>

namespace sdds{

class StringSet{
    unsigned count{0u};
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
