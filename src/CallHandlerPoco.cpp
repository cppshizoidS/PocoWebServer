#include "CallHandlerPoco.h"

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Stringifier.h>

using Poco::JSON::Parser;
using Poco::JSON::Object;
using Poco::JSON::Stringifier;

void CallHandlerPoco::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
    auto resp = Parser().parse(request.stream()).extract<Object::Ptr>();
    Object ans;
    ans.set("answer", "Hello " + resp->getValue<std::string>("name"));
    Stringifier w;
    w.stringify(ans, response.send());
}
