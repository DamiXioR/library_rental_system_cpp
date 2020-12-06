#pragma once
#include <string>
#include "IProduct.hpp"

class IDocument : public IProduct {
public:
    IDocument(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction);
    IDocument(std::string documentId, std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction);
    IDocument(IDocument& anotherIDocument);
    IDocument(IDocument&& anotherIDocument);
    IDocument& operator=(IDocument& anotherIDocument);
    IDocument& operator=(IDocument&& anotherIDocument);
    ~IDocument() = default;

    std::string getTitle() const
    {
        return title_;
    }
    std::string getAuthor() const
    {
        return author_;
    }
    std::string getLiteratureType() const
    {
        return literatureType_;
    }
    std::string getPublisher() const
    {
        return publisher_;
    }
    std::string getYearOfProduction() const
    {
        return yearOfProduction_;
    }
    std::string getDocumentId() const
    {
        return documentId_;
    }

private:
    std::string title_{};
    std::string author_{};
    std::string literatureType_{};
    std::string publisher_{};
    std::string yearOfProduction_{};
    std::string documentId_{};
};
