#pragma once
#include <fstream>
#include <string>

class IFileHandler {
public:
    IFileHandler(std::string fileName);
    IFileHandler(IFileHandler& anotherFile) = delete;
    IFileHandler& operator=(IFileHandler anotherFile) = delete;
    IFileHandler& operator=(IFileHandler&& anotherFile) = delete;
    virtual ~IFileHandler();

    std::string getFileNameWithExtension() const
    {
        return fileNameWithExtension_;
    }
    std::fstream* getWorkingFile()
    {
        return workingFile_;
    }

private:
    std::string fileNameWithExtension_{};
    std::fstream* workingFile_{};
};
