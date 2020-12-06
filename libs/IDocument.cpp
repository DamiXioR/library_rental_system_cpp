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
    individualProductId_ = std::to_string(IProduct::productId_);
}

IDocument::IDocument(std::string documentId, std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : IProduct(false),
      title_(title),
      author_(author),
      literatureType_(literatureType),
      publisher_(publisher),
      yearOfProduction_(yearOfProduction)
{
    individualProductId_ = documentId;
}

IDocument::IDocument(IDocument& anotherIDocument)
    : IProduct(false),
      title_(anotherIDocument.getTitle()),
      author_(anotherIDocument.getAuthor()),
      literatureType_(anotherIDocument.getLiteratureType()),
      publisher_(anotherIDocument.getPublisher()),
      yearOfProduction_(anotherIDocument.getYearOfProduction())
{
}

IDocument::IDocument(IDocument&& anotherIDocument)
    : IProduct(false),
      title_(std::move(anotherIDocument.getTitle())),
      author_(std::move(anotherIDocument.getAuthor())),
      literatureType_(std::move(anotherIDocument.getLiteratureType())),
      publisher_(std::move(anotherIDocument.getPublisher())),
      yearOfProduction_(std::move(anotherIDocument.getYearOfProduction()))
{
    individualProductId_ = anotherIDocument.getIndividualProductId();
}

IDocument& IDocument::operator=(IDocument& anotherIDocument)
{
    IProduct(false);
    title_ = anotherIDocument.getTitle();
    author_ = anotherIDocument.getAuthor();
    literatureType_ = anotherIDocument.getLiteratureType();
    publisher_ = anotherIDocument.getPublisher();
    yearOfProduction_ = anotherIDocument.getYearOfProduction();
    individualProductId_ = anotherIDocument.getIndividualProductId();
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
    individualProductId_ = std::move(anotherIDocument.getIndividualProductId());
    return *this;
}
