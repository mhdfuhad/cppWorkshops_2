//
//  Collection.h
//  Workshop 5
//
//  Created by Mohammad Fuhad Uddin on 2021-06-28.
//  Seneca ID: 135341196
//  Seneca Email: fmohammad15@myseneca.ca
//  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef Collection_h
#define Collection_h

#include <iostream>
#include <string>

namespace sdds {

template<typename T>
class Collection{
    std::string m_Name{};
    T* arr{nullptr};
    size_t arrSize{0};
    void (*m_observer)(const Collection<T>&, const T&){nullptr};
public:
    Collection(const std::string& name) : m_Name(name) {};
    Collection(const Collection& obj) = delete;
    Collection& operator=(const Collection& obj) = delete;
    ~Collection(){
        delete[] arr;
        arr = nullptr;
    };
    
    const std::string& name() const{
        return m_Name;
    };
    
    size_t size() const{
        return arrSize;
    };
    
    void setObserver(void (*observer)(const Collection<T>&, const T&)){
        m_observer = observer;
    };
    
    Collection<T>& operator+=(const T& item){
        bool exists = false;
        
        T* temp{nullptr};
        for(size_t i = 0; i < size() && !exists; i++){
            if(item.title() == arr[i].title()){
                exists = true;
            }
        }
        
        if(!exists){
            temp = new T[size() + 1];
            for(size_t i = 0; i < size(); i++){
                temp[i] = arr[i];
            }
            temp[size()] = T(item);
            
            delete[] arr;
            arr = temp;
            arrSize++;
            if(m_observer != nullptr) m_observer(*this, item);
        }
        return *this;
    };
    
    T& operator[](size_t idx) const{
        if (idx < 0 || idx >= size()) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.");
        }
        else {
            return arr[idx];
        }
    };
    
    T* operator[](const std::string& title) const{
        bool exists = false;
        size_t i;
        for (i = 0;i < size() && !exists; i++) {
            if(title == arr[i].title()){
                exists = true;
            }
        }
        if (exists)
            return &arr[i - 1];
        else
            return nullptr;
    };
    
    friend std::ostream& operator<<(std::ostream& ostr, const Collection& obj) {
        for (size_t i = 0; i < obj.size(); i++) {
            ostr << obj.arr[i];
        }
        return ostr;
    }
    
};


}

#endif /* Collection_h */
