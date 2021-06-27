// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// 2021/06/26 - Mohammad

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
        std::string temp;
        size_t i = 0;
        std::ifstream fin(argv[1]);
        if(fin.is_open()){
            while(getline(fin, temp, '\n')){
                if(temp[0] != '#'){
                    library[i] = Book(temp);
                    i++;
                }
            }
        }
        else{
            std::cerr << "ERROR: File cannot be opened.\n";
            exit(AppErrors::CannotOpenFile);
        }
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

    auto updatePrice = [usdToCadRate, gbpToCadRate](Book& obj){
        if(obj.country() == "US"){
            obj.price() = obj.price() * usdToCadRate;
        }else if(obj.country() == "UK" && obj.year() <= 1999 && obj.year() >= 1990){
            obj.price() = obj.price() * gbpToCadRate;
        };
    };

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";

    for(auto& e : library){
        std::cout << e;
    }

	std::cout << "-----------------------------------------\n\n";

    for(auto& e : library){
        updatePrice(e);
    }

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";

    for(auto& e : library){
        std::cout << e;
    }

	std::cout << "-----------------------------------------\n";

	return 0;
}
