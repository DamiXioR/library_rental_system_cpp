#pragma once
#include "IProductManager.hpp"

class LibProductManager : public IProductManager {
public:
    LibProductManager(std::vector<Book*>* allBooksInLibrary);
    LibProductManager(LibProductManager& anotherLibProductManager) = delete;
    LibProductManager(LibProductManager&& anotherLibProductManager) = delete;
    LibProductManager& operator=(LibProductManager& anotherLibProductManager) = delete;
    LibProductManager& operator=(LibProductManager&& anotherLibProductManager) = delete;
    ~LibProductManager() = default;

    void addNewBook(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction);
    void removeBook(std::string productId);
    void checkBooksList();
};
