//
//  Book.cpp
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-26.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iomanip>
#include <string>
#include "Book.h"

using namespace std;

namespace sdds {

Book::Book() {};

Book::Book(const string& strBook){
    string temp;
        
    //insert Author
    temp = getString(strBook, ',');
    m_Author = removeSpaces(temp);
    
    //insert Title
    temp = getString(strBook, ',');
    m_Title = removeSpaces(temp);
    
    //insert Country
    temp = getString(strBook,',');
    m_Country = removeSpaces(temp);
    
    //insert Price
    temp = getString(strBook,',');
    m_Price = stod(removeSpaces(temp));
    
    //insert Year of Publication
    temp = getString(strBook,',');
    m_Year = stoi(removeSpaces(temp));
    
    //insert description
    temp = getString(strBook,'\0');
    m_Desc = removeSpaces(temp);
};

const string& Book::title() const{
    return m_Title;
};

const string& Book::country() const{
    return m_Country;
};

const size_t& Book::year() const{
    return m_Year;
};

double& Book::price(){
    return m_Price;
};

ostream& operator<<(ostream& ostr,const Book& obj){
    ostr << right << setw(20) << obj.m_Author << " | ";
    ostr << right << setw(22) << obj.title() << " | ";
    ostr << right << setw(5) << obj.country() << " | ";
    ostr << setw(4) << obj.year() << " | ";
    ostr << right << setw(6) << fixed << setprecision(2) << obj.m_Price << " | ";
    ostr << left << obj.m_Desc << endl;
    
    return ostr;
};

string Book::removeSpaces(string& str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
};

string Book::getString(const string& str, char check){
    static unsigned long firstPos = 0u;
    static unsigned long endPos = 0u;
    unsigned long charCount = 0u;
    string extracted;
    
    endPos = str.find(check, firstPos);
    charCount = endPos - firstPos;
    extracted = str.substr(firstPos, charCount);
    firstPos = endPos + 1;
    
    return extracted;
}

}
