// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// 2021/07 - Mohammad Fuhad Uddin
// Seneca ID: 135341196
// Seneca Email: fmohammad15@myseneca.ca


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
        
        for(size_t i = 0; i < desc.size(); i++){
            for(size_t j = 0; j < price.size(); j++){
                if(desc[i].code == price[j].code){
                    Product* obj = new Product(desc[i].desc, price[j].price);
                    obj->validate();
                    priceList += obj;
                    delete obj;
                    obj = nullptr;
                }
            }
        }
        
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

        for(size_t i = 0; i < desc.size(); i++){
            for(size_t j = 0; j < price.size(); j++){
                if(desc[i].code == price[j].code){
                    std::unique_ptr<Product> obj(new Product(desc[i].desc, price[j].price));
                    obj->validate();
                    priceList += obj;
                }
            }
        }

		return priceList;
	}
}
