#include "IndexHandler.h"

#include <Poco/Net/HTTPServerResponse.h>

using namespace Poco::Net;

void IndexHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) {
    auto& stream = response.send();
    stream << "Hello world!";
}