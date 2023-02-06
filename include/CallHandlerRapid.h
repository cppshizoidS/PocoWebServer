#pragma once

#include <Poco/Net/HTTPRequestHandler.h>

class CallHandlerRapid : public Poco::Net::HTTPRequestHandler {
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};
