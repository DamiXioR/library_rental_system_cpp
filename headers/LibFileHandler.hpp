#pragma once
#include "IFileHandler.hpp"

class LibFileHandler : public IFileHandler {
public:
    LibFileHandler(std::string fileName);
    LibFileHandler(LibFileHandler& anotherLibFile) = delete;
    LibFileHandler(LibFileHandler&& anotherLibFile) = delete;
    LibFileHandler& operator=(LibFileHandler& anotherLibFile) = delete;
    LibFileHandler& operator=(LibFileHandler&& anotherLibFile) = delete;
    ~LibFileHandler() = default;
};
