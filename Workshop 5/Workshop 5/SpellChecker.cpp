//
//  SpellChecker.cpp
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-27.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;
namespace sdds {

size_t SpellChecker::CNT[]{0};

SpellChecker::SpellChecker(const char* filename){
        ifstream fin(filename);
        if(fin){
            string temp;
            size_t i = 0;
            size_t pos = 0;
            while(getline(fin, temp, '\n')){
                m_badWords[i] = temp.substr(0, temp.find_first_of(' '));
                pos = temp.find_last_of(' ') + 1;
                m_goodWords[i] = temp.substr(pos, '\n');
                i++;
            }
        }else{
            throw "Bad file name!";
        }
};

void SpellChecker::operator()(std::string& text){
    size_t pos = 0;
    for(unsigned i = 0; i < noOfWords;){
        pos = text.find(m_badWords[i]);
        if(pos != string::npos){
            size_t count = m_badWords[i].length();
            text.replace(pos, count, m_goodWords[i]);
            CNT[i]++; //count each instance of replacement
        }else{
            i++; //when the mispelled word is not found anymore then move to next bad word for checking
        }
    }
    
};

void SpellChecker::showStatistics(std::ostream& out) const{
    out << "Spellchecker Statistics" << endl;
    for(unsigned i = 0; i < noOfWords; i++){
        out << right << setw(15) << m_badWords[i] << ": " << CNT[i] << " replacements" << endl;
    }
};


}
