#include "IProduct.hpp"

unsigned IProduct::productId_ = 0;

IProduct::IProduct()
{
    productId_++;
}
