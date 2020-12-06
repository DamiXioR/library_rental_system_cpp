#include "LibClient.hpp"

LibClient::LibClient(std::string name, std::string surname, std::string address)
    : IClient(name, surname, address)
{
}

LibClient::LibClient(std::string clientIndividualId, std::string name, std::string surname, std::string address)
    : IClient(clientIndividualId, name, surname, address)
{
}
