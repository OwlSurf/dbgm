cmake_minimum_required(VERSION 3.21.2)

project(TestDebugMessages)

set(CMAKE_CXX_STANDARD 14)
#add_compile_definitions(DEBUG)

include(FetchContent)
FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/9406a60c7839052e4944ea4dbc8344762a89f9bd.zip
	  )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)  

include_directories(../Inc)
add_library(dbgm STATIC ../Src/dbgm.c)

enable_testing()
add_executable(
	  runtest
	  test.cpp
	  )
target_link_libraries(
	      runtest
	      dbgm
	      gtest_main
	      )

include(GoogleTest)
gtest_discover_tests(runtest)
