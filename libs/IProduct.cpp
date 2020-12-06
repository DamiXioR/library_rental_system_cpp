#include "IProduct.hpp"

unsigned IProduct::productId_ = 0;

IProduct::IProduct(bool isNewProduct)
{
    if (isNewProduct) {
        productId_++;
    }
}

void IProduct::setProductId(unsigned productId)
{
    productId_ = productId;
}
