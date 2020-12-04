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
}
void IProductManager::removeProduct(IProduct* libProduct)
{
}