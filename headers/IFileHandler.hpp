#pragma once
#include <fstream>
#include <sstream>
#include <string>

class IFileHandler {
public:
    IFileHandler(std::string fileName);
    IFileHandler(IFileHandler& anotherFile) = delete;
    IFileHandler(IFileHandler&& anotherFile) = delete;
    IFileHandler& operator=(IFileHandler anotherFile) = delete;
    IFileHandler& operator=(IFileHandler&& anotherFile) = delete;
    virtual ~IFileHandler();

    std::string getFileNameWithExtension() const
    {
        return fileNameWithExtension_;
    }
    std::fstream* getWorkingFile() const
    {
        return workingFile_;
    }
    std::stringstream* getReadFromFile() const
    {
        return readFiles_;
    }

    void readFromFile();
    void writeInFile(std::stringstream* dataToSaveInFile);

private:
    std::string fileNameWithExtension_{};
    std::fstream* workingFile_{};
    std::stringstream* readFiles_{};
};
