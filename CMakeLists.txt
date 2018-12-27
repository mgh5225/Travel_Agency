cmake_minimum_required(VERSION 3.12.3)
project(Travel_Agency)

set(CMAKE_CXX_STANDARD 14)

add_executable(Travel_Agency main.cpp Admin/admin.cpp Admin/admin.h Drivers/drivers.cpp Drivers/drivers.h Users/users.cpp Users/users.h)