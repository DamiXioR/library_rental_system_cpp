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

    //Hyperion
    std::string titlePanLodOgr = "Pan Lodowego Ogrodu - tom I";
    std::string authorJaroslawGrzedowicz = "Jarosław Grzędowicz";
    std::string publisherFabrykaSlow = "Fabryka Słów";
    std::string year2005 = "2005";
};

TEST_F(LibProductManagerTest, ShouldLoadVectorOfIProducts)
{
    Book* diunaBook = new Book(titleDiuna, authorFrankHerbert, typeSciFi, publisherChiltonBooks, year1965);
    Book* hyperionBook = new Book(titleHyperion, authorDanSimmons, typeSciFi, publisherAmber, year1989);
    Book* panLodOgrBook = new Book(titlePanLodOgr, authorJaroslawGrzedowicz, typeSciFi, publisherFabrykaSlow, year2005);

    std::vector<IProduct*>* productListInit = new std::vector<IProduct*> {
        diunaBook,
        hyperionBook,
        panLodOgrBook};

    LibProductManager* libProdMan = new LibProductManager(productListInit);


    delete diunaBook;
    delete hyperionBook;
    delete panLodOgrBook;
    delete libProdMan;
}
