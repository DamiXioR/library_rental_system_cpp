#include "IClient.hpp"

unsigned IClient::clientId_ = 0;

IClient::IClient(std::string name, std::string surname, std::string address)
    : name_(name), surname_(surname), address_(address)
{
    clientId_++;
}
