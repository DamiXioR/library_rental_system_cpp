#pragma once

class IProduct {
public:
    IProduct();
    IProduct& operator=(IProduct anotherProduct);
    virtual ~IProduct();

    static unsigned productId_;
};
