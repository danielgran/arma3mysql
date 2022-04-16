file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_library(${BINARY}_lib SHARED ${SOURCES})
target_link_libraries(arma3mysql_lib mysqlcppconn ssl.1.1)

set_target_properties(arma3mysql_lib PROPERTIES PREFIX "")
set_target_properties(arma3mysql_lib PROPERTIES OUTPUT_NAME "A3MySQL")
set_target_properties(arma3mysql_lib PROPERTIES SUFFIX "_x64.so")

#apt install aptitude libboost-all-dev