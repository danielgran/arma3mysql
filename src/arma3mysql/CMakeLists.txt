file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_library(${BINARY}_lib SHARED ${SOURCES})
target_link_libraries(arma3mysql_lib mysqlcppconn ssl.1.1)

#apt install aptitude libboost-all-dev