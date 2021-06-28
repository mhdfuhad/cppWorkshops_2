//
//  SpellChecker.h
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-27.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_SpellChecker_h
#define SDDS_SpellChecker_h

#include <iostream>

namespace sdds{

constexpr unsigned noOfWords = 6;

class SpellChecker{
    std::string m_badWords[noOfWords];
    std::string m_goodWords[noOfWords];
    static size_t CNT[noOfWords];
public:
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& out) const;
};

}

#endif /* SDDS_SpellChecker_h */
