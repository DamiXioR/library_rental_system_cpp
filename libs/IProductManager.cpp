#include "IProductManager.hpp"

IProductManager::IProductManager(std::vector<IProduct*>* productList)
    : productList_(productList)
{
}

IProductManager::~IProductManager()
{
    for(auto& everyProduct : *productList_){
        delete everyProduct;
    }
    delete productList_;
}
