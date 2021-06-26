//
//  Book.h
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-26.
//

#ifndef SDDS_Book_h
#define SDDS_Book_h

#include <string>

namespace sdds{

class Book{
    std::string m_Author{};
    std::string m_Title{};
    std::string m_Country{};
    size_t m_Year{0};
    double m_Price{0.0};
    std::string m_Desc{};
    std::string removeSpaces(std::string& str); //function written by author in WS4
    std::string getString(const std::string& str, char check = '\0'); //function written by author in WS4
public:
    Book();
    Book(const std::string& strBook);
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    friend std::ostream& operator<<(std::ostream& ostr,const Book& obj);
};

}

#endif /* SDDS_Book_h */
