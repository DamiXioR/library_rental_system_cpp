#include <gtest/gtest.h>

#include "Book.hpp"
#include "LibProductManager.hpp"

class LibProductManagerTest : public testing::Test {
public:
    //Type
    std::string typeSciFi = "sci-fi";

    //Diuna
    std::string idDiuna = "22313312";
    std::string titleDiuna = "Diuna";
    std::string authorFrankHerbert = "Frank Herbert";
    std::string publisherChiltonBooks = "Chilton Books";
    std::string year1965 = "1965";

    //Hyperion
    std::string idHyperion = "4127372";
    std::string titleHyperion = "Hyperion";
    std::string authorDanSimmons = "Dan Simmons";
    std::string publisherAmber = "Amber";
    std::string year1989 = "1989";

    //Pan Lodowego Ogrodu
    std::string idPanLodOgr = "884563445";
    std::string titlePanLodOgr = "Pan Lodowego Ogrodu - tom I";
    std::string authorJaroslawGrzedowicz = "Jarosław Grzędowicz";
    std::string publisherFabrykaSlow = "Fabryka Słów";
    std::string year2005 = "2005";

    //Nation
    std::string idNation = "5314843462";
    std::string titleNation = "Nation";
    std::string authorTerryPratchett = "Terry Pratchet";
    std::string publisherDoubleday = "Doubleday";
    std::string year2008 = "2008";

    //Books container
    std::vector<Book*>* bookListInitWithTwoBooks = new std::vector<Book*>{
        new Book(idDiuna, titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965),
        new Book(idHyperion, titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989)
        };

    //Books list size
    std::vector<unsigned> booksListSize{
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Product id
    std::vector<unsigned> productsIdCounter{
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    void resetProductId()
    {
        Book::productId_ = 0;
    }

    void setProductId(unsigned productIdToSet)
    {
        Book::productId_ = productIdToSet;
    }

    LibProductManager* libProdMan = new LibProductManager(bookListInitWithTwoBooks);

    ~LibProductManagerTest()
    {
        delete libProdMan;
    }
};

TEST_F(LibProductManagerTest, ShouldLoadVectorOfIProducts)
{
   
    EXPECT_EQ(libProdMan->getAllBooksInLibrary()->size(), booksListSize[2]);
    
}

TEST_F(LibProductManagerTest, ShouldLoadProductsToProductVectorByUseCTorWithIdArgument)
{
    
    setProductId(booksListSize[2]);

    libProdMan->getAllBooksInLibrary()->emplace_back(new Book(idPanLodOgr, titlePanLodOgr, authorJaroslawGrzedowicz, typeSciFi, publisherFabrykaSlow, year2005));
    EXPECT_EQ(libProdMan->getAllBooksInLibrary()->size(), booksListSize[3]);
    EXPECT_EQ(Book::productId_, productsIdCounter[2]);

    libProdMan->getAllBooksInLibrary()->emplace_back(new Book(idNation, titleNation, authorTerryPratchett, typeSciFi, publisherDoubleday, year2008));
    EXPECT_EQ(libProdMan->getAllBooksInLibrary()->size(), booksListSize[4]);
    EXPECT_EQ(Book::productId_, productsIdCounter[2]);
    
}

TEST_F(LibProductManagerTest, ShouldAddNewBooksToProductVectorByUseCTorWithoutIdArgument)
{
    setProductId(booksListSize[2]);

    libProdMan->addNewBook(titlePanLodOgr, authorJaroslawGrzedowicz, typeSciFi, publisherFabrykaSlow, year2005);
    EXPECT_EQ(libProdMan->getAllBooksInLibrary()->size(), booksListSize[3]);
    EXPECT_EQ(Book::productId_, productsIdCounter[3]);

    libProdMan->addNewBook(titleNation, authorTerryPratchett, typeSciFi, publisherDoubleday, year2008);
    EXPECT_EQ(libProdMan->getAllBooksInLibrary()->size(), booksListSize[4]);
    EXPECT_EQ(Book::productId_, productsIdCounter[4]);
}

TEST_F(LibProductManagerTest, ShouldRemoveProductsFromProductVector)
{
    libProdMan->removeBook(idHyperion);
    EXPECT_EQ(libProdMan->getAllBooksInLibrary()->size(), booksListSize[1]);

    libProdMan->removeBook(idDiuna);
    EXPECT_EQ(libProdMan->getAllBooksInLibrary()->size(), booksListSize[0]);
}
