# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/57/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/57/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mgh/Desktop/Travel_Agency

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mgh/Desktop/Travel_Agency

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/clion/57/bin/cmake/linux/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/snap/clion/57/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mgh/Desktop/Travel_Agency/CMakeFiles /home/mgh/Desktop/Travel_Agency/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mgh/Desktop/Travel_Agency/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Travel_Agency

# Build rule for target.
Travel_Agency: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Travel_Agency
.PHONY : Travel_Agency

# fast build rule for target.
Travel_Agency/fast:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/build
.PHONY : Travel_Agency/fast

Admin/AdminPanels/drivers.o: Admin/AdminPanels/drivers.cpp.o

.PHONY : Admin/AdminPanels/drivers.o

# target to build an object file
Admin/AdminPanels/drivers.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/drivers.cpp.o
.PHONY : Admin/AdminPanels/drivers.cpp.o

Admin/AdminPanels/drivers.i: Admin/AdminPanels/drivers.cpp.i

.PHONY : Admin/AdminPanels/drivers.i

# target to preprocess a source file
Admin/AdminPanels/drivers.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/drivers.cpp.i
.PHONY : Admin/AdminPanels/drivers.cpp.i

Admin/AdminPanels/drivers.s: Admin/AdminPanels/drivers.cpp.s

.PHONY : Admin/AdminPanels/drivers.s

# target to generate assembly for a file
Admin/AdminPanels/drivers.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/drivers.cpp.s
.PHONY : Admin/AdminPanels/drivers.cpp.s

Admin/AdminPanels/offers.o: Admin/AdminPanels/offers.cpp.o

.PHONY : Admin/AdminPanels/offers.o

# target to build an object file
Admin/AdminPanels/offers.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/offers.cpp.o
.PHONY : Admin/AdminPanels/offers.cpp.o

Admin/AdminPanels/offers.i: Admin/AdminPanels/offers.cpp.i

.PHONY : Admin/AdminPanels/offers.i

# target to preprocess a source file
Admin/AdminPanels/offers.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/offers.cpp.i
.PHONY : Admin/AdminPanels/offers.cpp.i

Admin/AdminPanels/offers.s: Admin/AdminPanels/offers.cpp.s

.PHONY : Admin/AdminPanels/offers.s

# target to generate assembly for a file
Admin/AdminPanels/offers.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/offers.cpp.s
.PHONY : Admin/AdminPanels/offers.cpp.s

Admin/AdminPanels/setting.o: Admin/AdminPanels/setting.cpp.o

.PHONY : Admin/AdminPanels/setting.o

# target to build an object file
Admin/AdminPanels/setting.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/setting.cpp.o
.PHONY : Admin/AdminPanels/setting.cpp.o

Admin/AdminPanels/setting.i: Admin/AdminPanels/setting.cpp.i

.PHONY : Admin/AdminPanels/setting.i

# target to preprocess a source file
Admin/AdminPanels/setting.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/setting.cpp.i
.PHONY : Admin/AdminPanels/setting.cpp.i

Admin/AdminPanels/setting.s: Admin/AdminPanels/setting.cpp.s

.PHONY : Admin/AdminPanels/setting.s

# target to generate assembly for a file
Admin/AdminPanels/setting.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/setting.cpp.s
.PHONY : Admin/AdminPanels/setting.cpp.s

Admin/AdminPanels/tickets.o: Admin/AdminPanels/tickets.cpp.o

.PHONY : Admin/AdminPanels/tickets.o

# target to build an object file
Admin/AdminPanels/tickets.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/tickets.cpp.o
.PHONY : Admin/AdminPanels/tickets.cpp.o

Admin/AdminPanels/tickets.i: Admin/AdminPanels/tickets.cpp.i

.PHONY : Admin/AdminPanels/tickets.i

# target to preprocess a source file
Admin/AdminPanels/tickets.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/tickets.cpp.i
.PHONY : Admin/AdminPanels/tickets.cpp.i

Admin/AdminPanels/tickets.s: Admin/AdminPanels/tickets.cpp.s

.PHONY : Admin/AdminPanels/tickets.s

# target to generate assembly for a file
Admin/AdminPanels/tickets.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/tickets.cpp.s
.PHONY : Admin/AdminPanels/tickets.cpp.s

Admin/AdminPanels/transaction.o: Admin/AdminPanels/transaction.cpp.o

.PHONY : Admin/AdminPanels/transaction.o

# target to build an object file
Admin/AdminPanels/transaction.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/transaction.cpp.o
.PHONY : Admin/AdminPanels/transaction.cpp.o

Admin/AdminPanels/transaction.i: Admin/AdminPanels/transaction.cpp.i

.PHONY : Admin/AdminPanels/transaction.i

# target to preprocess a source file
Admin/AdminPanels/transaction.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/transaction.cpp.i
.PHONY : Admin/AdminPanels/transaction.cpp.i

Admin/AdminPanels/transaction.s: Admin/AdminPanels/transaction.cpp.s

.PHONY : Admin/AdminPanels/transaction.s

# target to generate assembly for a file
Admin/AdminPanels/transaction.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/transaction.cpp.s
.PHONY : Admin/AdminPanels/transaction.cpp.s

Admin/AdminPanels/trips.o: Admin/AdminPanels/trips.cpp.o

.PHONY : Admin/AdminPanels/trips.o

# target to build an object file
Admin/AdminPanels/trips.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/trips.cpp.o
.PHONY : Admin/AdminPanels/trips.cpp.o

Admin/AdminPanels/trips.i: Admin/AdminPanels/trips.cpp.i

.PHONY : Admin/AdminPanels/trips.i

# target to preprocess a source file
Admin/AdminPanels/trips.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/trips.cpp.i
.PHONY : Admin/AdminPanels/trips.cpp.i

Admin/AdminPanels/trips.s: Admin/AdminPanels/trips.cpp.s

.PHONY : Admin/AdminPanels/trips.s

# target to generate assembly for a file
Admin/AdminPanels/trips.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/trips.cpp.s
.PHONY : Admin/AdminPanels/trips.cpp.s

Admin/AdminPanels/users.o: Admin/AdminPanels/users.cpp.o

.PHONY : Admin/AdminPanels/users.o

# target to build an object file
Admin/AdminPanels/users.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/users.cpp.o
.PHONY : Admin/AdminPanels/users.cpp.o

Admin/AdminPanels/users.i: Admin/AdminPanels/users.cpp.i

.PHONY : Admin/AdminPanels/users.i

# target to preprocess a source file
Admin/AdminPanels/users.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/users.cpp.i
.PHONY : Admin/AdminPanels/users.cpp.i

Admin/AdminPanels/users.s: Admin/AdminPanels/users.cpp.s

.PHONY : Admin/AdminPanels/users.s

# target to generate assembly for a file
Admin/AdminPanels/users.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/users.cpp.s
.PHONY : Admin/AdminPanels/users.cpp.s

Admin/admin.o: Admin/admin.cpp.o

.PHONY : Admin/admin.o

# target to build an object file
Admin/admin.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/admin.cpp.o
.PHONY : Admin/admin.cpp.o

Admin/admin.i: Admin/admin.cpp.i

.PHONY : Admin/admin.i

# target to preprocess a source file
Admin/admin.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/admin.cpp.i
.PHONY : Admin/admin.cpp.i

Admin/admin.s: Admin/admin.cpp.s

.PHONY : Admin/admin.s

# target to generate assembly for a file
Admin/admin.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/admin.cpp.s
.PHONY : Admin/admin.cpp.s

Admin/adminlogged.o: Admin/adminlogged.cpp.o

.PHONY : Admin/adminlogged.o

# target to build an object file
Admin/adminlogged.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/adminlogged.cpp.o
.PHONY : Admin/adminlogged.cpp.o

Admin/adminlogged.i: Admin/adminlogged.cpp.i

.PHONY : Admin/adminlogged.i

# target to preprocess a source file
Admin/adminlogged.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/adminlogged.cpp.i
.PHONY : Admin/adminlogged.cpp.i

Admin/adminlogged.s: Admin/adminlogged.cpp.s

.PHONY : Admin/adminlogged.s

# target to generate assembly for a file
Admin/adminlogged.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Admin/adminlogged.cpp.s
.PHONY : Admin/adminlogged.cpp.s

BankAccounts/account_func.o: BankAccounts/account_func.cpp.o

.PHONY : BankAccounts/account_func.o

# target to build an object file
BankAccounts/account_func.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/BankAccounts/account_func.cpp.o
.PHONY : BankAccounts/account_func.cpp.o

BankAccounts/account_func.i: BankAccounts/account_func.cpp.i

.PHONY : BankAccounts/account_func.i

# target to preprocess a source file
BankAccounts/account_func.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/BankAccounts/account_func.cpp.i
.PHONY : BankAccounts/account_func.cpp.i

BankAccounts/account_func.s: BankAccounts/account_func.cpp.s

.PHONY : BankAccounts/account_func.s

# target to generate assembly for a file
BankAccounts/account_func.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/BankAccounts/account_func.cpp.s
.PHONY : BankAccounts/account_func.cpp.s

Drivers/drivers.o: Drivers/drivers.cpp.o

.PHONY : Drivers/drivers.o

# target to build an object file
Drivers/drivers.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Drivers/drivers.cpp.o
.PHONY : Drivers/drivers.cpp.o

Drivers/drivers.i: Drivers/drivers.cpp.i

.PHONY : Drivers/drivers.i

# target to preprocess a source file
Drivers/drivers.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Drivers/drivers.cpp.i
.PHONY : Drivers/drivers.cpp.i

Drivers/drivers.s: Drivers/drivers.cpp.s

.PHONY : Drivers/drivers.s

# target to generate assembly for a file
Drivers/drivers.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Drivers/drivers.cpp.s
.PHONY : Drivers/drivers.cpp.s

Users/users.o: Users/users.cpp.o

.PHONY : Users/users.o

# target to build an object file
Users/users.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Users/users.cpp.o
.PHONY : Users/users.cpp.o

Users/users.i: Users/users.cpp.i

.PHONY : Users/users.i

# target to preprocess a source file
Users/users.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Users/users.cpp.i
.PHONY : Users/users.cpp.i

Users/users.s: Users/users.cpp.s

.PHONY : Users/users.s

# target to generate assembly for a file
Users/users.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/Users/users.cpp.s
.PHONY : Users/users.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/main.cpp.s
.PHONY : main.cpp.s

someThingNecessary.o: someThingNecessary.cpp.o

.PHONY : someThingNecessary.o

# target to build an object file
someThingNecessary.cpp.o:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/someThingNecessary.cpp.o
.PHONY : someThingNecessary.cpp.o

someThingNecessary.i: someThingNecessary.cpp.i

.PHONY : someThingNecessary.i

# target to preprocess a source file
someThingNecessary.cpp.i:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/someThingNecessary.cpp.i
.PHONY : someThingNecessary.cpp.i

someThingNecessary.s: someThingNecessary.cpp.s

.PHONY : someThingNecessary.s

# target to generate assembly for a file
someThingNecessary.cpp.s:
	$(MAKE) -f CMakeFiles/Travel_Agency.dir/build.make CMakeFiles/Travel_Agency.dir/someThingNecessary.cpp.s
.PHONY : someThingNecessary.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... Travel_Agency"
	@echo "... edit_cache"
	@echo "... Admin/AdminPanels/drivers.o"
	@echo "... Admin/AdminPanels/drivers.i"
	@echo "... Admin/AdminPanels/drivers.s"
	@echo "... Admin/AdminPanels/offers.o"
	@echo "... Admin/AdminPanels/offers.i"
	@echo "... Admin/AdminPanels/offers.s"
	@echo "... Admin/AdminPanels/setting.o"
	@echo "... Admin/AdminPanels/setting.i"
	@echo "... Admin/AdminPanels/setting.s"
	@echo "... Admin/AdminPanels/tickets.o"
	@echo "... Admin/AdminPanels/tickets.i"
	@echo "... Admin/AdminPanels/tickets.s"
	@echo "... Admin/AdminPanels/transaction.o"
	@echo "... Admin/AdminPanels/transaction.i"
	@echo "... Admin/AdminPanels/transaction.s"
	@echo "... Admin/AdminPanels/trips.o"
	@echo "... Admin/AdminPanels/trips.i"
	@echo "... Admin/AdminPanels/trips.s"
	@echo "... Admin/AdminPanels/users.o"
	@echo "... Admin/AdminPanels/users.i"
	@echo "... Admin/AdminPanels/users.s"
	@echo "... Admin/admin.o"
	@echo "... Admin/admin.i"
	@echo "... Admin/admin.s"
	@echo "... Admin/adminlogged.o"
	@echo "... Admin/adminlogged.i"
	@echo "... Admin/adminlogged.s"
	@echo "... BankAccounts/account_func.o"
	@echo "... BankAccounts/account_func.i"
	@echo "... BankAccounts/account_func.s"
	@echo "... Drivers/drivers.o"
	@echo "... Drivers/drivers.i"
	@echo "... Drivers/drivers.s"
	@echo "... Users/users.o"
	@echo "... Users/users.i"
	@echo "... Users/users.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... someThingNecessary.o"
	@echo "... someThingNecessary.i"
	@echo "... someThingNecessary.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

