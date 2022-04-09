set(BINARY ${CMAKE_PROJECT_NAME})


include_directories(${PROJECT_SOURCE_DIR}/lib/mysql-connector-c++-8.0.28-linux/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/mysql-connector-c++-8.0.28-linux/lib64)
link_directories(${PROJECT_SOURCE_DIR}/lib/mysql-connector-c++-8.0.28-linux/lib64/private)

add_subdirectory(arma3mysql)
add_subdirectory(arma3mysqltest)