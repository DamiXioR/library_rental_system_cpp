#include "IFileHandler.hpp"
#include <exception>

IFileHandler::IFileHandler(std::string fileNameWithExtension)
    : fileNameWithExtension_(fileNameWithExtension)
{
    workingFile_ = new std::fstream(fileNameWithExtension_);

    try {
        if (!workingFile_->is_open()) {
            throw std::logic_error("SomethingWrongWithFile\n");
        }
    }
    catch (const std::logic_error& catchedError) {
        catchedError.what();
    }
}

IFileHandler::~IFileHandler()
{
    workingFile_->close();
    delete workingFile_;
}
