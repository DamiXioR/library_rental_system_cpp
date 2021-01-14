#include "IProductManager.hpp"

IProductManager::IProductManager(std::vector<Book*>* allBooksInLibrary)
    : allBooksInLibrary_(allBooksInLibrary)
{
}

IProductManager::~IProductManager()
{
    for(auto& everyBook : *allBooksInLibrary_){
        delete everyBook;
    }
    delete allBooksInLibrary_;
}
