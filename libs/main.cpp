#include <fstream>
#include <iostream>
#include "LibFileHandler.hpp"
#include "LibraryRentalSystem.hpp"

int main()
{
    LibFileHandler* firstFile = new LibFileHandler("fileWriteIn.txt");

    std::stringstream* dataToWriteInFile = new std::stringstream("Hello world!\n Nice to meet You world!\n");
    firstFile->writeInFile(dataToWriteInFile);
    firstFile->readFromFile();

    std::string temporaryLine{};

    while(*firstFile->getReadFromFile() >> temporaryLine) {
        std::cout << temporaryLine << "\n";
    }

    delete dataToWriteInFile;
    delete firstFile;

    return 0;
}
