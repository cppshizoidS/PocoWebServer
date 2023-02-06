#include "CallHandlerRapid.h"

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>

namespace {
    rapidjson::Document parseRequest(Poco::Net::HTTPServerRequest& request) {
        rapidjson::Document data;
        rapidjson::IStreamWrapper isw(request.stream());
        data.ParseStream(isw);
        return data;
    }

    void dumpResponse(Poco::Net::HTTPServerResponse& response, rapidjson::Document& document) {
        rapidjson::OStreamWrapper osw(response.send());
        rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
        document.Accept(writer);
    }
}

void CallHandlerRapid::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
    auto data = parseRequest(request);
    std::string name = data["name"].GetString();
    rapidjson::Document answer(rapidjson::kObjectType);
    std::string v = "Hello " + name;
    rapidjson::Value value(v.c_str(), answer.GetAllocator());
    answer.AddMember("answer", value, answer.GetAllocator());
    dumpResponse(response, answer);
}
