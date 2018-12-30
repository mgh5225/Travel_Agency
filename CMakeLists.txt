cmake_minimum_required(VERSION 3.12.3)
project(Travel_Agency)

set(CMAKE_CXX_STANDARD 14)

add_executable(Travel_Agency main.cpp Admin/admin.cpp Admin/admin.h Drivers/drivers.cpp Drivers/drivers.h Users/users.cpp Users/users.h main.h Admin/adminlogged.cpp Admin/adminlogged.h BankAccounts/account_func.cpp BankAccounts/account_func.h Admin/AdminPanels/setting.cpp Admin/AdminPanels/setting.h Admin/AdminPanels/users.cpp Admin/AdminPanels/users.h Admin/AdminPanels/drivers.cpp Admin/AdminPanels/drivers.h Admin/AdminPanels/tickets.cpp Admin/AdminPanels/tickets.h Admin/AdminPanels/offers.cpp Admin/AdminPanels/offers.h Admin/AdminPanels/transaction.cpp Admin/AdminPanels/transaction.h Admin/AdminPanels/trips.cpp Admin/AdminPanels/trips.h)