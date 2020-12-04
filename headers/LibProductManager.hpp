#pragma once
#include "IProductManager.hpp"

class LibProductManager : public IProductManager {
public:
    LibProductManager(std::vector<IProduct>* productList);
    LibProductManager(LibProductManager& anotherLibProductManager) = delete;
    LibProductManager& operator=(LibProductManager anotherLibProductManager) = delete;
    LibProductManager& operator=(LibProductManager&& anotherLibProductManager) = delete;
    ~LibProductManager();
};
