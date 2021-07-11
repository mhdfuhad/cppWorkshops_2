//
//  SongCollection.cpp
//  Workshop 7
//
//  Created by Mohammad Fuhad Uddin on 2021-07-12.
//

#include <iomanip>
#include <algorithm>
#include <fstream>
#include "SongCollection.h"

using namespace std;
namespace sdds{

static unsigned long firstPos = 0u;

SongCollection::SongCollection(string fileName){
    ifstream fin(fileName);
    string temp, temp2;
    Song track;
    
    if(fin){
        while(getline(fin, temp, '\n')){
            temp2 = getString(temp, 25);
            track.m_Title = removeSpaces(temp2);;
            
            temp2 = getString(temp, 25);
            track.m_Artist = removeSpaces(temp2);
            
            temp2 = getString(temp, 25);
            track.m_Album = removeSpaces(temp2);
            
            temp2  = getString(temp, 5);
            removeSpaces(temp2);
            track.m_Year = (!temp2.empty() ? stoi(temp2) : 0);
            
            temp2 = getString(temp, 5);
            removeSpaces(temp2);
            track.m_Length = stoi(temp2);
            
            temp2 = getString(temp, 5);
            removeSpaces(temp2);
            track.m_Price = stod(temp2);
            
            collection.push_back(track);
            
            firstPos = 0u;
        }
    }
    else{
        throw "Invalid filename";
    }
};

void SongCollection::display(ostream& out) const{
    for_each(collection.begin(), collection.end(), [&out](const Song& theSong){
        out << theSong << endl;
    });
};

ostream& operator<<(ostream& out, const Song& theSong){
    out << "| " << left << setw(20) << theSong.m_Title << " | ";
    out << left << setw(15) << theSong.m_Artist << " | ";
    out << left << setw(20) << theSong.m_Album << " | ";
    out << right << setw(6);
    if (theSong.m_Year != 0)
        out << theSong.m_Year;
    else
        out << ' ';
    out << " | " << theSong.m_Length / 60 << ":";
    out << setw(2) << setfill('0') << theSong.m_Length % 60 << " | " << setfill(' ');
    out << setw(3) << setprecision(2) << fixed << theSong.m_Price << " |";
    return out;
};

string SongCollection::removeSpaces(string& str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
};

string SongCollection::getString(const string& str, unsigned long length){
    unsigned long charCount = length;
    string extracted;
    
    extracted = str.substr(firstPos, charCount);
    firstPos = length + firstPos;
    return extracted;
};

}
