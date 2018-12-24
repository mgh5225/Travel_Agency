cmake_minimum_required(VERSION 3.13)
project(Travel_Agancy)

set(CMAKE_CXX_STANDARD 14)

add_executable(Travel_Agancy main.cpp Admin/admin.cpp Admin/admin.h Drivers/drivers.cpp Drivers/drivers.h Users/users.cpp Users/users.h)