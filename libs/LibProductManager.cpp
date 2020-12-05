#include "LibProductManager.hpp"
#include "Book.hpp"

#include <algorithm>
#include <iostream>

LibProductManager::LibProductManager(std::vector<IProduct*>* productList)
    : IProductManager(productList)
{
}

LibProductManager::~LibProductManager()
{
}

void LibProductManager::checkProductList()
{
    std::for_each(getProductList()->begin(), getProductList()->end(), [](IProduct* everyProduct) {
        Book* everyBook = dynamic_cast<Book*>(everyProduct);
        std::cout << everyBook->getTitle() << "\n";
    });
}