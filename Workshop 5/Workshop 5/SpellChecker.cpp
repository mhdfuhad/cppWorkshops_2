//
//  SpellChecker.cpp
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-27.
//

#include <iostream>
#include <string>
#include <fstream>
#include "SpellChecker.h"

using namespace std;
namespace sdds {
size_t CNT = 0;

SpellChecker::SpellChecker(const char* filename){
    try{
        ifstream fin(filename);
        if(fin){
            string temp;
            size_t i = 0;
            size_t pos = 0;
            while(getline(fin, temp, '\n')){
                m_badWords[i] = temp.substr(0, temp.find_first_of(' '));
                pos = temp.find_last_of(' ') + 1;
                m_goodWords[i] = temp.substr(pos, '\0');
                i++;
            }
        }else{
            throw "Bad file name!";
        }
    }
    catch(const char* msg){
        cerr << msg << endl;
    }
    
};

void SpellChecker::operator()(std::string& text){
    size_t pos = 0;
    for(auto i = 0, j = 0; j < noOfWords; i++){
        pos = text.find(m_badWords[j]);
        if(pos != string::npos){
            size_t count = text.find(' ', pos) - pos;
            text.replace(pos, count, m_goodWords[j]);
            CNT++; //count each instance of replacement
        }else{
            j++; //when the mispelled word is not found anymore then move to next bad word
        }
    }
    
};

void SpellChecker::showStatistics(std::ostream& out) const{
    
};


}
