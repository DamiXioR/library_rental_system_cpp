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
};

TEST_F(LibProductManagerTest, ShouldLoadVectorOfIProducts)
{
    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book* hyperionBook = new Book(titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);

    std::vector<IProduct*>* productListInit = new std::vector<IProduct*>{
        diunaBook,
        hyperionBook};

    LibProductManager* libProdMan = new LibProductManager(productListInit);

    Book* panLodOgrBook = new Book(titlePanLodOgr, authorJaroslawGrzedowicz, typeSciFi, publisherFabrykaSlow, year2005);

    libProdMan->addProduct(panLodOgrBook);

    const unsigned productListSize3 = 3;

    EXPECT_EQ(libProdMan->getProductList()->size(), productListSize3);

    Book* nationBook = new Book(titleNation, authorTerryPratchett, typeSciFi, publisherDoubleday, year2008);

    libProdMan->addProduct(nationBook);

    const unsigned productListSize4 = 4;

    EXPECT_EQ(libProdMan->getProductList()->size(), productListSize4);

    delete diunaBook;
    delete hyperionBook;
    delete panLodOgrBook;
    delete nationBook;
    delete libProdMan;
}
