#include "Server.h"

#include "HandlerFactory.h"

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Util/HelpFormatter.h>

using namespace Poco::Net;
using namespace Poco::Util;

MyServer::MyServer()
    : _helpRequested(false)
{}

void MyServer::initialize(Application& self) {
    loadConfiguration();
    ServerApplication::initialize(self);
}

void MyServer::defineOptions(OptionSet& options) {
    ServerApplication::defineOptions(options);

    options.addOption(
            Option("help", "h", "display argument help information")
                    .required(false)
                    .repeatable(false)
                    .callback(OptionCallback<MyServer>(this, &MyServer::handleHelp)));
}

void MyServer::handleHelp(const std::string& name, const std::string& value) {
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader(
            "A web server.");
    helpFormatter.format(std::cout);
    stopOptionsProcessing();
    _helpRequested = true;
}

int MyServer::main(const std::vector<std::string> &args) {
    if (!_helpRequested) {
        int port = config().getInt("MyServer.port", 9980);
        ServerSocket svs(port);
        HTTPServer srv(new HandlerFactory(), svs, new HTTPServerParams());
        srv.start();
        waitForTerminationRequest();
        srv.stop();
    }
    return Application::EXIT_OK;
}