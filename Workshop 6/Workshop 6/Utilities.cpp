//
//  Utilities.cpp
//  Workshop 6
//
//  Created by Mohammad Fuhad Uddin on 2021-07-05.
//

#include "Utilities.h"

using namespace std;
namespace sdds{

string removeSpaces(string& str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
};

Vehicle* createInstance(istream& in){
    string m_Type;
    getline(in, m_Type, ',');
    removeSpaces(m_Type);
    
    if (m_Type[0] == 'c' || m_Type[0] == 'C'){
        return new Car(in);
    }
    else
        return nullptr;
};

}
