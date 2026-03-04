cmake_minimum_required(VERSION 3.12)

find_package(GTest REQUIRED)

add_executable(gtest_version gtest_version.cpp)

set_target_properties(gtest_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(gtest_version
    PRIVATE "${CMAKE_SOURCE_DIR}"
)

target_link_libraries(gtest_version
    PRIVATE helloworld GTest::gtest
)

if (MSVC)
    target_compile_options(gtest_version PRIVATE
        /W4
    )
else ()
    target_compile_options(gtest_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

add_test(gtest_version gtest_version)
