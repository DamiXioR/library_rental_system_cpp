#include <gtest/gtest.h>
#include "LibClient.hpp"

#include <string>

class LibClientTest : public ::testing::Test {
public:
    unsigned firstId = 1;
    unsigned secondId = 2;
    unsigned thirdId = 3;

    std::string nameJohn = "John";
    std::string surnameKovalsky = "Kovalsky";
    std::string addressWarsaw = "Warsaw";

    std::string nameKobe = "Kobe";
    std::string surnameBryant = "Bryant";
    std::string addressLosAngeles = "Los Angeles";

    std::string nameMicheal = "Micheal";
    std::string surnameCorleone = "Corleone";
    std::string addressSicily = "Sicily";

    IClient* everyClient{};
};

TEST_F(LibClientTest, ShouldReturnLibClientFeatures)
{
    LibClient* kovalsky = new LibClient(nameJohn, surnameKovalsky, addressWarsaw);
    everyClient = kovalsky;

    EXPECT_EQ(everyClient->getName(), nameJohn);
    EXPECT_EQ(everyClient->getSurname(), surnameKovalsky);
    EXPECT_EQ(everyClient->getAddress(), addressWarsaw);
    EXPECT_EQ(IClient::clientId_, firstId);

    delete kovalsky;

    LibClient* bryant = new LibClient(nameKobe, surnameBryant, addressLosAngeles);
    everyClient = bryant;

    EXPECT_EQ(everyClient->getName(), nameKobe);
    EXPECT_EQ(everyClient->getSurname(), surnameBryant);
    EXPECT_EQ(everyClient->getAddress(), addressLosAngeles);
    EXPECT_EQ(IClient::clientId_, secondId);

    delete bryant;

    LibClient* corleone = new LibClient(nameMicheal, surnameCorleone, addressSicily);
    everyClient = corleone;

    EXPECT_EQ(everyClient->getName(), nameMicheal);
    EXPECT_EQ(everyClient->getSurname(), surnameCorleone);
    EXPECT_EQ(everyClient->getAddress(), addressSicily);
    EXPECT_EQ(IClient::clientId_, thirdId);

    delete corleone;
}
