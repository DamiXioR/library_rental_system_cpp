cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(LibraryRentalSystem)

# ************************* DOWNLOAD GTEST *************************** 

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# ****************************************************************** 

#SET STATIC VALUES

set(LIBS_SRC
    libs/IRentalSystem.cpp
    libs/LibraryRentalSystem.cpp
    libs/IProductManager.cpp
    libs/LibProductManager.cpp
    libs/IProduct.cpp
    libs/Book.cpp
    libs/IClient.cpp
    libs/LibClient.cpp
    libs/IClientManager.cpp
    libs/LibClientManager.cpp
    libs/IFileHandler.cpp
    libs/LibFileHandler.cpp
)

set(TESTS_SRC
    tests/LibraryRentalSystem-ut.cpp
    tests/LibProductManager-ut.cpp
    tests/Book-ut.cpp
    tests/LibClient-ut.cpp
    tests/LibClientManager-ut.cpp
    tests/LibFileHandler-ut.cpp
)

set(COMPILE_FLAGS
    -Werror
    -Wconversion
    -Wpedantic
)

#ADD LIBRARIES

add_library(${PROJECT_NAME}-lib ${LIBS_SRC})
include_directories(headers)
link_libraries(gtest)

#ADD EXECUTABLE FILES - PROGRAM

add_executable(${PROJECT_NAME} libs/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILE_FLAGS})

#ADD EXECUTABLE FILES - TESTS_SRC

add_executable(${PROJECT_NAME}-ut tests/testsMain.cpp ${TESTS_SRC})

target_link_libraries(${PROJECT_NAME}-ut PUBLIC ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME}-ut PUBLIC ${COMPILE_FLAGS})

#ENABLE TESTING

add_test(${PROJECT_NAME}-tests ${PROJECT_NAME}-ut)
enable_testing()
