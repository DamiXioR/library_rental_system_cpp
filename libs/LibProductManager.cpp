#include "LibProductManager.hpp"
#include "Book.hpp"

#include <algorithm>
#include <iostream>

LibProductManager::LibProductManager(std::vector<Book*>* allBooksInLibrary)
    : IProductManager(allBooksInLibrary)
{
}

void LibProductManager::addNewBook(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
{
    allBooksInLibrary_->emplace_back(new Book(title, author, literatureType, publisher, yearOfProduction));
}

void LibProductManager::removeBook(std::string productId)
{
    if (!allBooksInLibrary_->empty()) {
        auto foundedAtPosition = std::find_if(allBooksInLibrary_->begin(), allBooksInLibrary_->end(), [productId](IProduct* everyProduct) {
            return (everyProduct->getIndividualProductId() == productId);
        });
        if (foundedAtPosition != allBooksInLibrary_->end()) {
            delete *foundedAtPosition;
            allBooksInLibrary_->erase(foundedAtPosition);
        }
    }
}

void LibProductManager::checkProductList()
{
    std::for_each(getProductList()->begin(), getProductList()->end(), [](IProduct* everyProduct) {
        IProduct* everyProductReader = everyProduct;
        std::cout << everyProductReader->getIndividualProductId() << "\n";
    });
}
