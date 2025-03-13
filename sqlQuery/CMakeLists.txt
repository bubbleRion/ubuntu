cmake_minimum_required(VERSION 3.00)

project(bookSql)

add_executable(bookSql bookSql.c)

target_include_directories(booksql PRIVATE /usr/include/mysql)
target_link_directories(booksql PRIVATE /usr/include/mysql)
target_link_libraries(booksql PRIVATE mysqlclient)