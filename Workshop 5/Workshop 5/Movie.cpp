//
//  Movie.cpp
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//

#include <string>
#include <iomanip>
#include <iostream>
#include "Movie.h"

using namespace std;
namespace sdds{

Movie::Movie() {};

const string& Movie::title() const{
    return m_Title;
};

Movie::Movie(const string& strMovie){
    string temp;
        
    //insert title
    temp = getString(strMovie, ',');
    m_Title = removeSpaces(temp);
    
    //insert Year
    temp = getString(strMovie, ',');
    m_Year = stoi(removeSpaces(temp));
    
    //insert Desc
    temp = getString(strMovie, '\0');
    m_Desc = removeSpaces(temp);
};

ostream& operator<<(ostream& ostr,const Movie& obj){
    
    ostr << right <<setw(40) << obj.title() << " | ";
    ostr << setw(4) << obj.m_Year << " | ";
    ostr << obj.m_Desc << endl;
    
    return ostr;
}

string Movie::removeSpaces(string& str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
};

string Movie::getString(const string& str, char check){
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
