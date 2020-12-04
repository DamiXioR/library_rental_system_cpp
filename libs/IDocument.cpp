#include "IDocument.hpp"
#include <iostream>

IDocument::IDocument(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : title_(title),
      author_(author),
      literatureType_(literatureType),
      publisher_(publisher),
      yearOfProduction_(yearOfProduction)
{
    documentId_ = IProduct::productId_;
}

IDocument::IDocument(IDocument&& anotherIDocument)
    : title_(std::move(anotherIDocument.getTitle())),
      author_(std::move(anotherIDocument.getAuthor())),
      literatureType_(std::move(anotherIDocument.getLiteratureType())),
      publisher_(std::move(anotherIDocument.getPublisher())),
      yearOfProduction_(std::move(anotherIDocument.getYearOfProduction())),
      documentId_(std::move(anotherIDocument.getDocumentId()))
{
}

IDocument& IDocument::operator=(IDocument&& anotherIDocument)
{
    title_ = std::move(anotherIDocument.getTitle());
    author_ = std::move(anotherIDocument.getAuthor());
    literatureType_ = std::move(anotherIDocument.getLiteratureType());
    publisher_ = std::move(anotherIDocument.getPublisher());
    yearOfProduction_ = std::move(anotherIDocument.getYearOfProduction());
    documentId_ = std::move(anotherIDocument.getDocumentId());
    return *this;
}
