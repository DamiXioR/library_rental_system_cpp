#include <gtest/gtest.h>
#include "Book.hpp"

class BookTest : public ::testing::Test {
public:
    std::string titleDiuna = "Diuna";
    std::string authorFrankHerbert = "Frank Herbert";
    std::string typeSciFi = "sci-fi";
    std::string publisherChiltonBooks = "Chilton Books";
    std::string year1965 = "1965";
    IDocument* everyBook{};
};

TEST_F(BookTest, ShouldReturnBookFeatures)
{
    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    everyBook = diunaBook;
    EXPECT_EQ(diunaBook->getTitle(), titleDiuna);
    delete diunaBook;
}