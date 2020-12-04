#pragma once

class IProduct {
public:
    IProduct();
    IProduct(IProduct& anotherProduct) = delete;
    IProduct(IProduct&& anotherProduct) = default;
    IProduct& operator=(IProduct& anotherProduct) = delete;
    IProduct& operator=(IProduct&& anotherProduct) = default;
    virtual ~IProduct() = default;

    static unsigned productId_;
};
