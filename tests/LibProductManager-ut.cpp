#include <gtest/gtest.h>

#include "Book.hpp"
#include "LibProductManager.hpp"

class LibProductManagerTest : public testing::Test {
public:
    //Type
    std::string typeSciFi = "sci-fi";

    //Diuna
    std::string titleDiuna = "Diuna";
    std::string authorFrankHerbert = "Frank Herbert";
    std::string publisherChiltonBooks = "Chilton Books";
    std::string year1965 = "1965";

    //Hyperion
    std::string titleHyperion = "Hyperion";
    std::string authorDanSimmons = "Dan Simmons";
    std::string publisherAmber = "Amber";
    std::string year1989 = "1989";

    //Pan Lodowego Ogrodu
    std::string titlePanLodOgr = "Pan Lodowego Ogrodu - tom I";
    std::string authorJaroslawGrzedowicz = "Jarosław Grzędowicz";
    std::string publisherFabrykaSlow = "Fabryka Słów";
    std::string year2005 = "2005";

    //Nation
    std::string titleNation = "Nation";
    std::string authorTerryPratchett = "Terry Pratchet";
    std::string publisherDoubleday = "Doubleday";
    std::string year2008 = "2008";

    //Books

    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book* hyperionBook = new Book(titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    Book* panLodOgrBook = new Book(titlePanLodOgr, authorJaroslawGrzedowicz, typeSciFi, publisherFabrykaSlow, year2005);
    Book* nationBook = new Book(titleNation, authorTerryPratchett, typeSciFi, publisherDoubleday, year2008);

    //Products containers

    std::vector<IProduct*>* productListInit = new std::vector<IProduct*>{
        diunaBook,
        hyperionBook};

    ~LibProductManagerTest()
    {
        delete diunaBook;
        delete hyperionBook;
        delete panLodOgrBook;
        delete nationBook;
    }
};

TEST_F(LibProductManagerTest, ShouldLoadVectorOfIProducts)
{
    LibProductManager* libProdMan = new LibProductManager(productListInit);
    const unsigned productListSize2 = 2;

    delete libProdMan;
}

TEST_F(LibProductManagerTest, ShouldAddProductsToProductVector)
{
    LibProductManager* libProdMan = new LibProductManager(productListInit);

    libProdMan->addProduct(panLodOgrBook);
    const unsigned productListSize3 = 3;
    EXPECT_EQ(libProdMan->getProductList()->size(), productListSize3);

    libProdMan->addProduct(nationBook);
    const unsigned productListSize4 = 4;
    EXPECT_EQ(libProdMan->getProductList()->size(), productListSize4);

    delete libProdMan;
}

TEST_F(LibProductManagerTest, ShouldRemoveProductsFromProductVector)
{
    LibProductManager* libProdMan = new LibProductManager(productListInit);

    libProdMan->removeProduct(hyperionBook);
    const unsigned productListSize1 = 1;
    EXPECT_EQ(libProdMan->getProductList()->size(), productListSize1);

    libProdMan->removeProduct(diunaBook);
    const unsigned productListSize0 = 0;
    EXPECT_EQ(libProdMan->getProductList()->size(), productListSize0);

    delete libProdMan;
}
