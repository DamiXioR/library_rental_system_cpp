#include "Book.hpp"
#include <iostream>

Book::Book(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : IProduct(true),
      title_(title),
      author_(author),
      literatureType_(literatureType),
      publisher_(publisher),
      yearOfProduction_(yearOfProduction)
{
    individualProductId_ = std::to_string(IProduct::productId_);
}

Book::Book(std::string documentId, std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : IProduct(false),
      title_(title),
      author_(author),
      literatureType_(literatureType),
      publisher_(publisher),
      yearOfProduction_(yearOfProduction)
{
    individualProductId_ = documentId;
}

Book::Book(Book& anotherBook)
    : IProduct(false),
      title_(anotherBook.getTitle()),
      author_(anotherBook.getAuthor()),
      literatureType_(anotherBook.getLiteratureType()),
      publisher_(anotherBook.getPublisher()),
      yearOfProduction_(anotherBook.getYearOfProduction())
{
}

Book::Book(Book&& anotherBook)
    : IProduct(false),
      title_(std::move(anotherBook.getTitle())),
      author_(std::move(anotherBook.getAuthor())),
      literatureType_(std::move(anotherBook.getLiteratureType())),
      publisher_(std::move(anotherBook.getPublisher())),
      yearOfProduction_(std::move(anotherBook.getYearOfProduction()))
{
    individualProductId_ = anotherBook.getIndividualProductId();
}

Book& Book::operator=(Book& anotherBook)
{
    IProduct(false);
    title_ = anotherBook.getTitle();
    author_ = anotherBook.getAuthor();
    literatureType_ = anotherBook.getLiteratureType();
    publisher_ = anotherBook.getPublisher();
    yearOfProduction_ = anotherBook.getYearOfProduction();
    individualProductId_ = anotherBook.getIndividualProductId();
    return *this;
}

Book& Book::operator=(Book&& anotherBook)
{
    IProduct(false);
    title_ = std::move(anotherBook.getTitle());
    author_ = std::move(anotherBook.getAuthor());
    literatureType_ = std::move(anotherBook.getLiteratureType());
    publisher_ = std::move(anotherBook.getPublisher());
    yearOfProduction_ = std::move(anotherBook.getYearOfProduction());
    individualProductId_ = std::move(anotherBook.getIndividualProductId());
    return *this;
}
