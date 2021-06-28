//
//  Movie.h
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_Movie_h
#define SDDS_Movie_h

#include <string>
#include <iostream>

namespace sdds{

class Movie{
    std::string m_Title{};
    size_t m_Year{0};
    std::string m_Desc{};
    std::string removeSpaces(std::string& str); //function written by author in WS4
    std::string getString(const std::string& str, char check = '\0'); //function written by author in WS4
public:
    Movie();
    const std::string& title() const;
    Movie(const std::string& strMovie);
    friend std::ostream& operator<<(std::ostream& ostr,const Movie& obj);
    template<typename T>
    void fixSpelling(T& spellChecker){
        spellChecker(m_Title);
        spellChecker(m_Desc);
    };
};

}

#endif /* SDDS_Movie_h */
