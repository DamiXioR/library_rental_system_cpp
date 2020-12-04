#pragma once

#include <vector>
#include "IProduct.hpp"

class IProductManager {
public:
    IProductManager(std::vector<IProduct>* productList);
    IProductManager(IProductManager& anotherProductManager) = delete;
    IProductManager(IProductManager&& anotherProductManager) = delete;
    IProductManager& operator=(IProductManager& anotherProductManager) = delete;
    IProductManager& operator=(IProductManager&& anotherProductManager) = delete;
    virtual ~IProductManager();

    virtual void addProduct(IProduct* libProduct);
    virtual void removeProduct(IProduct* libProduct);
    std::vector<IProduct>* getProductList() const
    {
        return productList_;
    }

private:
    std::vector<IProduct>* productList_{};
};
