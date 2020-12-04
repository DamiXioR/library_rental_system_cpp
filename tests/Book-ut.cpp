#include <gtest/gtest.h>
#include "Book.hpp"

#include <utility>

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
    unsigned idFourth = 4;
    unsigned idFifth = 5;
    unsigned idSixth = 6;
    unsigned idSeventh = 7;
    unsigned idEight = 8;
    unsigned idNineth = 9;
    unsigned idTenth = 10;
    unsigned idEleventh = 11;
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

TEST_F(BookTest, ShouldInitObjectWhenUsingMoveCtor)
{
    Book diunaBook = Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book secondDiunaBook = std::move(diunaBook);

    EXPECT_EQ(diunaBook.getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook.getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook.getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook.getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook.getYearOfProduction(), year1965);
    EXPECT_EQ(diunaBook.getDocumentId(), idFourth);
    EXPECT_EQ(IProduct::productId_, idFifth);

    EXPECT_EQ(secondDiunaBook.getTitle(), titleDiuna);
    EXPECT_EQ(secondDiunaBook.getAuthor(), authorFrankHerbert);
    EXPECT_EQ(secondDiunaBook.getLiteratureType(), typeSciFi);
    EXPECT_EQ(secondDiunaBook.getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(secondDiunaBook.getYearOfProduction(), year1965);
    EXPECT_EQ(secondDiunaBook.getDocumentId(), idFourth);
    EXPECT_EQ(IProduct::productId_, idFifth);
}

TEST_F(BookTest, ShouldInitObjectWhenUsingMoveAsignmentOperator)
{
    Book diunaBook = Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book oldDestroyedBook = Book(titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    oldDestroyedBook = std::move(diunaBook);

    EXPECT_EQ(diunaBook.getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook.getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook.getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook.getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook.getYearOfProduction(), year1965);
    EXPECT_EQ(diunaBook.getDocumentId(), idSixth);
    EXPECT_EQ(IProduct::productId_, idSeventh);

    EXPECT_EQ(oldDestroyedBook.getTitle(), titleDiuna);
    EXPECT_EQ(oldDestroyedBook.getAuthor(), authorFrankHerbert);
    EXPECT_EQ(oldDestroyedBook.getLiteratureType(), typeSciFi);
    EXPECT_EQ(oldDestroyedBook.getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(oldDestroyedBook.getYearOfProduction(), year1965);
    EXPECT_EQ(oldDestroyedBook.getDocumentId(), idSixth);
    EXPECT_EQ(IProduct::productId_, idSeventh);
}

TEST_F(BookTest, ShouldInitObjectWhenUsingMoveCtorWhenInitWithPointer)
{
    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book* oldDestroyedBook = new Book(std::move(*diunaBook));

    EXPECT_EQ(diunaBook->getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook->getYearOfProduction(), year1965);
    EXPECT_EQ(diunaBook->getDocumentId(), idEight);
    EXPECT_EQ(IProduct::productId_, idNineth);

    EXPECT_EQ(oldDestroyedBook->getTitle(), titleDiuna);
    EXPECT_EQ(oldDestroyedBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(oldDestroyedBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(oldDestroyedBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(oldDestroyedBook->getYearOfProduction(), year1965);
    EXPECT_EQ(oldDestroyedBook->getDocumentId(), idEight);
    EXPECT_EQ(IProduct::productId_, idNineth);

    delete diunaBook;
    delete oldDestroyedBook;
}

TEST_F(BookTest, ShouldInitObjectWhenUsingMoveAsignmentOperatorWhenInitWithPointer)
{
    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book* oldDestroyedBook = new Book(titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    *oldDestroyedBook = std::move(*diunaBook);

    EXPECT_EQ(diunaBook->getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook->getYearOfProduction(), year1965);
    EXPECT_EQ(diunaBook->getDocumentId(), idTenth);
    EXPECT_EQ(IProduct::productId_, idEleventh);

    EXPECT_EQ(oldDestroyedBook->getTitle(), titleDiuna);
    EXPECT_EQ(oldDestroyedBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(oldDestroyedBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(oldDestroyedBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(oldDestroyedBook->getYearOfProduction(), year1965);
    EXPECT_EQ(oldDestroyedBook->getDocumentId(), idTenth);
    EXPECT_EQ(IProduct::productId_, idEleventh);

    delete diunaBook;
    delete oldDestroyedBook;
}
