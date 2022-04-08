project(arma3mysql)

include_directories(/usr/local/mysql-connector-c++-8.0.28/include)
link_directories(/usr/local/mysql-connector-c++-8.0.28/lib64)
#add_executable(arma3mysql library.cpp)

add_library(arma3mysql SHARED library.cpp)

target_link_libraries(arma3mysql mysqlcppconn)
target_link_libraries(arma3mysql ssl.1.1)

# Install mysqlconnector, and link openssl