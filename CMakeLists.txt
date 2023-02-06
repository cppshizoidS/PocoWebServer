cmake_minimum_required(VERSION 3.16)
project(Server)

set(CMAKE_CXX_STANDARD 17)

find_package(Poco REQUIRED Data Net Util XML)
find_package(rapidjson)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(Server ${SOURCES})
target_link_libraries(Server PUBLIC Poco::Data Poco::Net Poco::Util Poco::XML)
