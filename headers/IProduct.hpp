#pragma once

#include <string>

class IProduct {
public:
    IProduct(bool isNewProduct);
    IProduct(IProduct& anotherProduct) = default;
    IProduct(IProduct&& anotherProduct) = default;
    IProduct& operator=(IProduct& anotherProduct) = default;
    IProduct& operator=(IProduct&& anotherProduct) = default;
    virtual ~IProduct() = default;

    static unsigned productId_;

private:
    void setProductId(unsigned productId);
};
