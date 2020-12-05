#include "LibProductManager.hpp"

LibProductManager::LibProductManager(std::vector<IProduct*>* productList)
    : IProductManager(productList)
{
}

LibProductManager::~LibProductManager()
{
}
