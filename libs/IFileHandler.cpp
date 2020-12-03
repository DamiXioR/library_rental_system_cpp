#include "IFileHandler.hpp"
#include <exception>
#include <iostream>

IFileHandler::IFileHandler(std::string fileNameWithExtension)
    : fileNameWithExtension_(fileNameWithExtension)
{
    workingFile_ = new std::fstream(fileNameWithExtension_, std::fstream::in | std::fstream::out | std::fstream::app);

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
    delete readFiles_;
    delete workingFile_;
}

void IFileHandler::readFromFile()
{
    unsigned startPoint = 0;
    workingFile_->clear();
    workingFile_->seekg(startPoint);

    std::stringstream* readData = new std::stringstream();
    std::string temporyLineData{};
    while (std::getline(*workingFile_, temporyLineData)) {
        *readData << temporyLineData;
    }
    readFiles_ = readData;
}

void IFileHandler::writeInFile(std::stringstream* dataToSaveInFile)
{
    *workingFile_ << dataToSaveInFile->rdbuf();
}
