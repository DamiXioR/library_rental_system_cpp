#pragma once

#include <string>
#include <vector>
#include "IProduct.hpp"

class IProductManager {
public:
    IProductManager(std::vector<IProduct*>* productList);
    IProductManager(IProductManager& anotherProductManager) = delete;
    IProductManager(IProductManager&& anotherProductManager) = delete;
    IProductManager& operator=(IProductManager& anotherProductManager) = delete;
    IProductManager& operator=(IProductManager&& anotherProductManager) = delete;
    virtual ~IProductManager();

    virtual void checkProductList() = 0;
    std::vector<IProduct*>* getProductList() const
    {
        return productList_;
    }

protected:
    std::vector<IProduct*>* productList_{};
};
