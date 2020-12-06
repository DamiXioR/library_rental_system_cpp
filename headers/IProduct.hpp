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

    std::string getIndividualProductId() const
    {
        return individualProductId_;
    }

    static unsigned productId_;

protected:
    void setProductId(unsigned productId);
    std::string individualProductId_{};
};
