#include "IProductManager.hpp"

#include <algorithm>

IProductManager::IProductManager(std::vector<IProduct*>* productList)
    : productList_(productList)
{
}

IProductManager::~IProductManager()
{
    delete productList_;
}

void IProductManager::addProduct(IProduct* libProduct)
{
    productList_->emplace_back(libProduct);
}
void IProductManager::removeProduct(IProduct* libProduct)
{
    if (!productList_->empty()) {
        auto foundedAtPosition = std::find_if(productList_->begin(), productList_->end(), [libProduct](IProduct* everyProduct) {
            return (everyProduct == libProduct);
        });
        if (foundedAtPosition != productList_->end()) {
            productList_->erase(foundedAtPosition);
        }
    }
}
