set(BINARY ${CMAKE_PROJECT_NAME})

if(LINUX)
    message(Running_linux)
    include_directories(/usr/include/mariadb)
    link_directories(/usr/lib/x86_64-linux-gnu)
endif()

if(APPLE)
    message(Running_MacOS)

    include_directories(${PROJECT_SOURCE_DIR}/lib/googletest-macos-1.11.0/include)
    link_directories(${PROJECT_SOURCE_DIR}/lib/googletest-macos-1.11.0/lib)

    include_directories(${PROJECT_SOURCE_DIR}/lib/boost-1.78-macos/include)
    link_directories(${PROJECT_SOURCE_DIR}/lib/boost-1.78-macos/lib)

    include_directories(${PROJECT_SOURCE_DIR}/lib/mysql-connector-c++-8.0.28-macos11-x86-64bit/include)
    link_directories(${PROJECT_SOURCE_DIR}/lib/mysql-connector-c++-8.0.28-macos11-x86-64bit/lib64)
    link_directories(${PROJECT_SOURCE_DIR}/lib/mysql-connector-c++-8.0.28-macos11-x86-64bit/lib64/private)
endif()

add_subdirectory(arma3mysql)
add_subdirectory(arma3mysqltest)