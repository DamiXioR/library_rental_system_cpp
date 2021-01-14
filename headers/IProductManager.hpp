#pragma once

#include <string>
#include <vector>
#include "IProduct.hpp"
#include "Book.hpp"

class IProductManager {
public:
    IProductManager(std::vector<Book*>* allBooksInLibrary);
    IProductManager(IProductManager& anotherProductManager) = delete;
    IProductManager(IProductManager&& anotherProductManager) = delete;
    IProductManager& operator=(IProductManager& anotherProductManager) = delete;
    IProductManager& operator=(IProductManager&& anotherProductManager) = delete;
    virtual ~IProductManager();

    virtual void checkProductList() = 0;
    std::vector<Book*>* getAllBooksInLibrary() const
    {
        return allBooksInLibrary_;
    }

protected:
    std::vector<Book*>* allBooksInLibrary_{};
};
