#include <gtest/gtest.h>
#include "Book.hpp"

#include <utility>
#include <vector>

class BookTest : public ::testing::Test {
public:
    //Diuna
    std::string idDiuna = "0014567";
    std::string titleDiuna = "Diuna";
    std::string authorFrankHerbert = "Frank Herbert";
    std::string typeSciFi = "sci-fi";
    std::string publisherChiltonBooks = "Chilton Books";
    std::string year1965 = "1965";

    //Hyperion
    std::string idHyperion = "0013671";
    std::string titleHyperion = "Hyperion";
    std::string authorDanSimmons = "Dan Simmons";
    std::string publisherAmber = "Amber";
    std::string year1989 = "1989";

    //Product id
    std::vector<unsigned> productsIdCounter{
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    void resetProductId()
    {
        IDocument::productId_ = 0;
    }

    void setProductId(unsigned productIdToSet)
    {
        IDocument::productId_ = productIdToSet;
    }
};

TEST_F(BookTest, ShouldCreateBookWithoutIncreaseProductId)
{
    resetProductId();
    Book* diunaBook = new Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[0]);
    delete diunaBook;

    Book* hyperionBook = new Book(idHyperion, titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[0]);
    delete hyperionBook;

    diunaBook = new Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[0]);
    delete diunaBook;
}

TEST_F(BookTest, ShouldCreateBookWithIncreaseProductId)
{
    resetProductId();
    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[1]);
    delete diunaBook;

    Book* hyperionBook = new Book(titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[2]);
    delete hyperionBook;

    diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[3]);
    delete diunaBook;
}

TEST_F(BookTest, ShouldSetProductIdAndCoopWithBookCtors)
{
    resetProductId();
    setProductId(productsIdCounter[7]);

    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[8]);
    delete diunaBook;

    Book* hyperionBook = new Book(titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[9]);
    delete hyperionBook;

    diunaBook = new Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    EXPECT_EQ(IDocument::productId_, productsIdCounter[9]);
    delete diunaBook;
}

TEST_F(BookTest, ShouldReturnBookFeatures)
{
    Book* diunaBook = new Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    EXPECT_EQ(diunaBook->getDocumentId(), idDiuna);
    EXPECT_EQ(diunaBook->getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook->getYearOfProduction(), year1965);

    delete diunaBook;

    Book* hyperionBook = new Book(idHyperion, titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    EXPECT_EQ(hyperionBook->getDocumentId(), idHyperion);
    EXPECT_EQ(hyperionBook->getTitle(), titleHyperion);
    EXPECT_EQ(hyperionBook->getAuthor(), authorDanSimmons);
    EXPECT_EQ(hyperionBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(hyperionBook->getPublisher(), publisherAmber);
    EXPECT_EQ(hyperionBook->getYearOfProduction(), year1989);

    delete hyperionBook;

    diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);

    delete diunaBook;
}

TEST_F(BookTest, ShouldInitObjectWhenUsingMoveCtor)
{
    resetProductId();
    Book diunaBook = Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book secondDiunaBook = std::move(diunaBook);

    EXPECT_EQ(diunaBook.getDocumentId(), idDiuna);
    EXPECT_EQ(diunaBook.getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook.getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook.getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook.getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook.getYearOfProduction(), year1965);

    EXPECT_EQ(secondDiunaBook.getDocumentId(), idDiuna);
    EXPECT_EQ(secondDiunaBook.getTitle(), titleDiuna);
    EXPECT_EQ(secondDiunaBook.getAuthor(), authorFrankHerbert);
    EXPECT_EQ(secondDiunaBook.getLiteratureType(), typeSciFi);
    EXPECT_EQ(secondDiunaBook.getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(secondDiunaBook.getYearOfProduction(), year1965);

    EXPECT_EQ(IDocument::productId_, productsIdCounter[0]);
}

TEST_F(BookTest, ShouldInitObjectWhenUsingMoveAsignmentOperator)
{
    resetProductId();
    Book diunaBook = Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book oldDestroyedBook = Book(idHyperion, titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    oldDestroyedBook = std::move(diunaBook);

    EXPECT_EQ(diunaBook.getDocumentId(), idDiuna);
    EXPECT_EQ(diunaBook.getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook.getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook.getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook.getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook.getYearOfProduction(), year1965);

    EXPECT_EQ(oldDestroyedBook.getDocumentId(), idDiuna);
    EXPECT_EQ(oldDestroyedBook.getTitle(), titleDiuna);
    EXPECT_EQ(oldDestroyedBook.getAuthor(), authorFrankHerbert);
    EXPECT_EQ(oldDestroyedBook.getLiteratureType(), typeSciFi);
    EXPECT_EQ(oldDestroyedBook.getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(oldDestroyedBook.getYearOfProduction(), year1965);

    EXPECT_EQ(IDocument::productId_, productsIdCounter[0]);
}

TEST_F(BookTest, ShouldInitObjectWhenUsingMoveCtorWhenInitWithPointer)
{
    resetProductId();
    Book* diunaBook = new Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book* oldDestroyedBook = new Book(std::move(*diunaBook));

    EXPECT_EQ(diunaBook->getDocumentId(), idDiuna);
    EXPECT_EQ(diunaBook->getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook->getYearOfProduction(), year1965);

    EXPECT_EQ(oldDestroyedBook->getDocumentId(), idDiuna);
    EXPECT_EQ(oldDestroyedBook->getTitle(), titleDiuna);
    EXPECT_EQ(oldDestroyedBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(oldDestroyedBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(oldDestroyedBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(oldDestroyedBook->getYearOfProduction(), year1965);

    EXPECT_EQ(IDocument::productId_, productsIdCounter[0]);

    delete diunaBook;
    delete oldDestroyedBook;
}

TEST_F(BookTest, ShouldInitObjectWhenUsingMoveAsignmentOperatorWhenInitWithPointer)
{
    resetProductId();
    Book* diunaBook = new Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book* oldDestroyedBook = new Book(idHyperion, titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    *oldDestroyedBook = std::move(*diunaBook);

    EXPECT_EQ(diunaBook->getDocumentId(), idDiuna);
    EXPECT_EQ(diunaBook->getTitle(), titleDiuna);
    EXPECT_EQ(diunaBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(diunaBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(diunaBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(diunaBook->getYearOfProduction(), year1965);

    EXPECT_EQ(oldDestroyedBook->getDocumentId(), idDiuna);
    EXPECT_EQ(oldDestroyedBook->getTitle(), titleDiuna);
    EXPECT_EQ(oldDestroyedBook->getAuthor(), authorFrankHerbert);
    EXPECT_EQ(oldDestroyedBook->getLiteratureType(), typeSciFi);
    EXPECT_EQ(oldDestroyedBook->getPublisher(), publisherChiltonBooks);
    EXPECT_EQ(oldDestroyedBook->getYearOfProduction(), year1965);

    EXPECT_EQ(IDocument::productId_, productsIdCounter[0]);

    delete diunaBook;
    delete oldDestroyedBook;
}
