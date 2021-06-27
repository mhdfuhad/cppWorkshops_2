//
//  SpellChecker.h
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-27.
//

#ifndef SDDS_SpellChecker_h
#define SDDS_SpellChecker_h

#include <iostream>

namespace sdds{

constexpr unsigned noOfWords = 6;

class SpellChecker{
    std::string m_badWords[noOfWords];
    std::string m_goodWords[noOfWords];
    static size_t CNT;
public:
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& out) const;
};

}

#endif /* SDDS_SpellChecker_h */
