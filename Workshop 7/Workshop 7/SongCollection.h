//
//  SongCollection.h
//  Workshop 7
//
//  Created by Mohammad Fuhad Uddin on 2021-07-12.
//

#ifndef SDDS_SongCollection_h
#define SDDS_SongCollection_h

#include <string>
#include <vector>

namespace sdds{

struct Song{
    std::string m_Artist{};
    std::string m_Title{};
    std::string m_Album{};
    double m_Price{0.0};
    size_t m_Year{0};
    size_t m_Length{0};
};

class SongCollection {
    std::vector<Song> collection;
    std::string removeSpaces(std::string& str);
    std::string getString(const std::string& str, unsigned long length);
public:
    SongCollection(std::string fileName);
    void display(std::ostream& out) const;
};
std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif /* SongCollection_h */
