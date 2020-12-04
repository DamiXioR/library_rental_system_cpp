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
{
    title_ = anotherIDocument.getTitle();
    author_ = anotherIDocument.getAuthor();
    literatureType_ = anotherIDocument.getLiteratureType();
    publisher_ = anotherIDocument.getPublisher();
    yearOfProduction_ = anotherIDocument.getYearOfProduction();
    documentId_ = anotherIDocument.getDocumentId();
}

IDocument& IDocument::operator=(IDocument&& anotherIDocument)
{
    title_ = anotherIDocument.getTitle();
    author_ = anotherIDocument.getAuthor();
    literatureType_ = anotherIDocument.getLiteratureType();
    publisher_ = anotherIDocument.getPublisher();
    yearOfProduction_ = anotherIDocument.getYearOfProduction();
    documentId_ = anotherIDocument.getDocumentId();
    return *this;
}
