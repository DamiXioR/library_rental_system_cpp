#pragma once

class IProduct {
public:
    IProduct();
    IProduct(IProduct& anotherProduct) = delete;
    IProduct& operator=(IProduct anotherProduct) = delete;
    IProduct& operator=(IProduct&& anotherProduct) = delete;
    virtual ~IProduct();

    static unsigned productId_;
};
