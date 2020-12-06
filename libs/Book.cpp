#include "Book.hpp"

Book::Book(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : IDocument(title,
                author,
                literatureType,
                publisher,
                yearOfProduction)
{
}

Book::Book(std::string bookId, std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : IDocument(bookId,
                title,
                author,
                literatureType,
                publisher,
                yearOfProduction)
{
}