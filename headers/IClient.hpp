#pragma once
#include <string>

class IClient {
public:
    IClient(std::string name, std::string surname, std::string address);
    IClient(std::string clientIndividualId, std::string name, std::string surname, std::string address);
    IClient(IClient& anotherClient) = delete;
    IClient(IClient&& anotherClient) = delete;
    IClient& operator=(IClient& anotherClient) = delete;
    IClient& operator=(IClient&& anotherClient) = delete;
    virtual ~IClient() {}

    std::string getName() const
    {
        return name_;
    }
    std::string getSurname() const
    {
        return surname_;
    }
    std::string getAddress() const
    {
        return address_;
    }
    std::string getClientIndividualId() const
    {
        return clientIndividualId_;
    }

    static unsigned clientId_;

private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string clientIndividualId_{};
};
