#include "LibProductManager.hpp"
#include "Book.hpp"

#include <algorithm>
#include <iostream>

LibProductManager::LibProductManager(std::vector<IProduct*>* productList)
    : IProductManager(productList)
{
}

void LibProductManager::addNewBook(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
{
    productList_->emplace_back(new Book(title, author, literatureType, publisher, yearOfProduction));
}

void LibProductManager::removeBook(std::string productId)
{
    if (!productList_->empty()) {
        auto foundedAtPosition = std::find_if(productList_->begin(), productList_->end(), [productId](IProduct* everyProduct) {
            return (everyProduct->getIndividualProductId() == productId);
        });
        if (foundedAtPosition != productList_->end()) {
            delete *foundedAtPosition;
            productList_->erase(foundedAtPosition);
        }
    }
}

void LibProductManager::checkProductList()
{
    std::for_each(getProductList()->begin(), getProductList()->end(), [](IProduct* everyProduct) {
        Book* everyBook = dynamic_cast<Book*>(everyProduct);
        std::cout << everyBook->getTitle() << "\n";
    });
}
