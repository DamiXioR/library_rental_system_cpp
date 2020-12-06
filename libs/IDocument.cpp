#include "IDocument.hpp"
#include <iostream>

IDocument::IDocument(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : IProduct(true),
      title_(title),
      author_(author),
      literatureType_(literatureType),
      publisher_(publisher),
      yearOfProduction_(yearOfProduction)
{
    documentId_ = std::to_string(IProduct::productId_);
}

IDocument::IDocument(std::string documentId, std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : IProduct(false),
      documentId_(documentId),
      title_(title),
      author_(author),
      literatureType_(literatureType),
      publisher_(publisher),
      yearOfProduction_(yearOfProduction)
{
}

IDocument::IDocument(IDocument& anotherIDocument)
    : IProduct(false),
      title_(anotherIDocument.getTitle()),
      author_(anotherIDocument.getAuthor()),
      literatureType_(anotherIDocument.getLiteratureType()),
      publisher_(anotherIDocument.getPublisher()),
      yearOfProduction_(anotherIDocument.getYearOfProduction()),
      documentId_(anotherIDocument.getDocumentId())
{
}

IDocument::IDocument(IDocument&& anotherIDocument)
    : IProduct(false),
      title_(std::move(anotherIDocument.getTitle())),
      author_(std::move(anotherIDocument.getAuthor())),
      literatureType_(std::move(anotherIDocument.getLiteratureType())),
      publisher_(std::move(anotherIDocument.getPublisher())),
      yearOfProduction_(std::move(anotherIDocument.getYearOfProduction())),
      documentId_(std::move(anotherIDocument.getDocumentId()))
{
}

IDocument& IDocument::operator=(IDocument& anotherIDocument)
{
    IProduct(false);
    title_ = anotherIDocument.getTitle();
    author_ = anotherIDocument.getAuthor();
    literatureType_ = anotherIDocument.getLiteratureType();
    publisher_ = anotherIDocument.getPublisher();
    yearOfProduction_ = anotherIDocument.getYearOfProduction();
    documentId_ = anotherIDocument.getDocumentId();
    return *this;
}

IDocument& IDocument::operator=(IDocument&& anotherIDocument)
{
    IProduct(false);
    title_ = std::move(anotherIDocument.getTitle());
    author_ = std::move(anotherIDocument.getAuthor());
    literatureType_ = std::move(anotherIDocument.getLiteratureType());
    publisher_ = std::move(anotherIDocument.getPublisher());
    yearOfProduction_ = std::move(anotherIDocument.getYearOfProduction());
    documentId_ = std::move(anotherIDocument.getDocumentId());
    return *this;
}
