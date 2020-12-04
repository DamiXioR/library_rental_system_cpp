#pragma once
#include "IDocument.hpp"

class Book : public IDocument {
public:
    Book(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction);
    Book(Book& anotherBook) = delete;
    Book(Book&& anotherBook) = default;
    Book& operator=(Book& anotherBook) = delete;
    Book& operator=(Book&& anotherBook) = default;
    ~Book() = default;
};
