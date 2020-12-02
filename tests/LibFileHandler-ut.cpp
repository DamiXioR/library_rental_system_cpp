#include <gtest/gtest.h>
#include <exception>
#include "LibFileHandler.hpp"

#include <string>

class LibFileHandlerTest : public testing::Test {
public:
    std::string fileName = "firstFile.txt";
    std::string fileName2 = "firstFile2.txt";
    std::string fileName3 = "firstFile3.txt";

    IFileHandler* everyFile{};
};

TEST_F(LibFileHandlerTest, ShouldNotThrowExceptionWhenFileIsOpen)
{
    EXPECT_NO_THROW(LibFileHandler{fileName});
    EXPECT_NO_THROW(LibFileHandler{fileName2});
    EXPECT_NO_THROW(LibFileHandler{fileName3});
}

TEST_F(LibFileHandlerTest, ShouldReturnLibFileHandlerFeatures)
{
    LibFileHandler* firstFile = new LibFileHandler(fileName);
    LibFileHandler* secondFile = new LibFileHandler(fileName2);
    LibFileHandler* thirdFile = new LibFileHandler(fileName3);

    everyFile = firstFile;
    EXPECT_EQ(everyFile->getFileNameWithExtension(), fileName);
    everyFile = secondFile;
    EXPECT_EQ(everyFile->getFileNameWithExtension(), fileName2);
    everyFile = thirdFile;
    EXPECT_EQ(everyFile->getFileNameWithExtension(), fileName3);

    delete firstFile;
    delete secondFile;
    delete thirdFile;
}
