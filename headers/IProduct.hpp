#pragma once

class IProduct {
public:
    IProduct();
    IProduct& operator=(IProduct anotherProduct);
    virtual ~IProduct();
private:
    static unsigned productId_;
};
