cmake_minimum_required(VERSION 3.13)
project(Travel_Agency)

set(CMAKE_CXX_STANDARD 14)

add_executable(Travel_Agency main.cpp Admin/admin.cpp Admin/admin.h Drivers/drivers.cpp Drivers/drivers.h Users/users.cpp Users/users.h Cities/cities.cpp Cities/cities.h BankAccounts/bankaccounts.cpp BankAccounts/bankaccounts.h Date/date.h)