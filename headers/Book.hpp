#pragma once
#include "IDocument.hpp"

class Book : public IDocument {
public:
    Book(std::string title, std::string author, std::string literatureType, std::string publisher, std::string yearOfProduction);
};
