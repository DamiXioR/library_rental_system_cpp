#include "IDocument.hpp"

IDocument::IDocument(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction)
    : title_(title),
      author_(author),
      literatureType_(literatureType),
      publisher_(publisher),
      yearOfProduction_(yearOfProduction)
{
}

IDocument::~IDocument() {}
