cmake_minimum_required(VERSION 3.12)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(test_version test_version.cpp)

set_target_properties(test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS "BOOST_TEST_DYN_LINK"
    INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIR};${CMAKE_SOURCE_DIR}"
)

target_link_libraries(test_version
    PRIVATE helloworld ${Boost_LIBRARIES}
)

if (MSVC)
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

add_test(test_version test_version)
