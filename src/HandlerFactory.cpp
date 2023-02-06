#include "HandlerFactory.h"

#include "IndexHandler.h"
#include "CallHandlerRapid.h"
#include "CallHandlerPoco.h"

#include <Poco/Net/HTTPServerRequest.h>

using namespace Poco::Net;

HTTPRequestHandler* HandlerFactory::createRequestHandler(const HTTPServerRequest& request) {
    if (request.getURI() == "/") {
        return new IndexHandler();
    } else if (request.getURI() == "/callrapid") {
        return new CallHandlerRapid();
    } else if (request.getURI() == "/callpoco") {
        return new CallHandlerPoco();
    } else {
        return nullptr;
    }
}
