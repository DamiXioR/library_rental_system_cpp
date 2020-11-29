#include <gtest/gtest.h>
#include "Book.hpp"

class BookTest : public ::testing::Test {
public:
    IDocument* everyBook{};
    //Diuna
    std::string titleDiuna = "Diuna";
    std::string authorFrankHerbert = "Frank Herbert";
    std::string typeSciFi = "sci-fi";
    std::string publisherChiltonBooks = "Chilton Books";
    std::string year1965 = "1965";

    //Hyperion
    std::string titleHyperion = "Hyperion";
    std::string authorDanSimmons = "Dan Simmons";
    std::string publisherAmber = "Amber";
    std::string year1989 = "1989";

    //Product ID
    unsigned idFirst = 1;
    unsigned idSecond = 2;
    unsigned idThird = 3;
};

TEST_F(BookTest, ShouldReturnBookFeatures)
{
    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    everyBook = diunaBook;
    EXPECT_EQ(diunaBook->getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook->getYearOfProduction(), year1965);
    EXPECT_EQ(IProduct::productId_, idFirst);
    
    delete diunaBook;

    Book* hyperionBook = new Book(titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    everyBook = hyperionBook;
    EXPECT_EQ(hyperionBook->getTitle(), titleHyperion);
    EXPECT_EQ(hyperionBook->getAuthor(), authorDanSimmons);
    EXPECT_EQ(hyperionBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(hyperionBook->getPublisher(), publisherAmber);
    EXPECT_EQ(hyperionBook->getYearOfProduction(), year1989);
    EXPECT_EQ(IProduct::productId_, idSecond);

    delete hyperionBook;

    diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    everyBook = diunaBook;
    EXPECT_EQ(IProduct::productId_, idThird);

    delete diunaBook;
}
