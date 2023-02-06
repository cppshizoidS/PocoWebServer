#pragma once

#include <Poco/Util/ServerApplication.h>

#include <string>


class MyServer : public Poco::Util::ServerApplication {
public:
    MyServer();
protected:
    void initialize(Poco::Util::Application& self) override;

    void defineOptions(Poco::Util::OptionSet& options) override;

    void handleHelp(const std::string& name, const std::string& value);

    int main(const std::vector<std::string>& args) override;
private:
    bool _helpRequested;
};