#include "IProductManager.hpp"
#include <algorithm>
#include <utility>

IProductManager::IProductManager(std::vector<IProduct>* productList)
    : productList_(productList)
{
}

IProductManager::~IProductManager()
{
    delete productList_;
}

void IProductManager::addProduct(IProduct* libProduct)
{
    productList_->emplace_back(std::move(*libProduct));
}
void IProductManager::removeProduct(IProduct* libProduct)
{
    //TO DO COPY CTOR FOR IPRODUCT
    /*
    if (!productList_->empty()) {
        auto foundedAtPosition = std::find(productList_->begin(), productList_->end(), libProduct);
        if (foundedAtPosition != productList_->end()) {
            productList_->erase(foundedAtPosition);
        }
    }
    */
}
