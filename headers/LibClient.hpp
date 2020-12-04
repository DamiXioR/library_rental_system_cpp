#pragma once
#include "IClient.hpp"
#include <string>

class LibClient : public IClient {
public:
    LibClient(std::string name, std::string surname, std::string address);
    LibClient(LibClient& anotherLibClient) = delete;
    LibClient(LibClient&& anotherLibClient) = delete;
    LibClient& operator=(LibClient& anotherLibClient) = delete;
    LibClient& operator=(LibClient&& anotherLibClient) = delete;
    ~LibClient() = default;
};
