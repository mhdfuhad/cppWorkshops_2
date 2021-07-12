//
//  SongCollection.cpp
//  Workshop 7
//
//  Created by Mohammad Fuhad Uddin on 2021-07-12.
//

#include <iomanip>
#include <algorithm>
#include <fstream>
#include <numeric>
#include "SongCollection.h"

using namespace std;
namespace sdds{

static unsigned long firstPos = 0u;
static unsigned long countSongs = 0u;

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
            track.m_price = stod(temp2);
            
            collection.push_back(track);
            
            firstPos = 0u;
        }
    }
    else{
        throw "Invalid filename";
    }
};

void SongCollection::sort(string fieldName){
    std::sort(collection.begin(), collection.end(), [fieldName](const Song& obj, const Song& obj2){
        if(fieldName == "title")
            return obj.m_Title < obj2.m_Title;
        else if(fieldName == "album")
            return obj.m_Album < obj2.m_Album;
        else if(fieldName == "length")
            return obj.m_Length < obj2.m_Length;
        else
            return false;
    });
};

void SongCollection::cleanAlbum(){
    for_each(collection.begin(), collection.end(), [](Song& obj){
        if(obj.m_Album == "[None]")
            obj.m_Album = "";
        else
            obj.m_Album = obj.m_Album;
    });
};

bool SongCollection::inCollection(string artist) const{
    countSongs = count_if(collection.begin(), collection.end(), [artist](const Song& obj){
        return artist == obj.m_Artist;
    });
    return countSongs > 0;
};

list<Song> SongCollection::getSongsForArtist(string artist) const{
    list<Song> trackList(countSongs);
    copy_if(collection.begin(), collection.end(), trackList.begin(), [artist](const Song& obj){
        return obj.m_Artist == artist;
    });
    return trackList;
};

void SongCollection::display(ostream& out) const{
    for_each(collection.begin(), collection.end(), [&out](const Song& theSong){
        out << theSong << endl;
    });
    
    size_t sum = accumulate(collection.begin(), collection.end(), 0, [](size_t total, const Song& song){
        return total += song.m_Length;
    });
    
    out << setw(89) << setfill('-') << '\n' << setfill(' ');
    out << "| " << setw(77) << right << "Total Listening Time: ";
    out << sum/3600 << ":" << (sum - ((sum/3600) * 3600))/60 << ":" << sum % 60 <<  " |" << endl;
    
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
    out << setw(3) << setprecision(2) << fixed << theSong.m_price << " |";
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
