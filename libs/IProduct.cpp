#include "IProduct.hpp"

unsigned IProduct::productId_ = 0;

IProduct::IProduct(){
    productId_++;
}

IProduct& IProduct::operator=(IProduct anotherProduct){
    productId_++;
    return *this;
}

IProduct::~IProduct(){
    productId_--;
}

