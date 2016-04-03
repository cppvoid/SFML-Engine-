project(engine)
cmake_minimum_required(VERSION 2.8)

FILE(GLOB SOURCE_FILES "inc/*.h" "src/*.cpp")

INCLUDE_DIRECTORIES("inc")
INCLUDE_DIRECTORIES("src")

#
## find SFML
#

find_package(SFML 2 REQUIRED system window graphics network audio)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

#
## find BOOST
#

find_package(Boost 1.60.0 REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

#
## compile
#

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#
## linking
#

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

#
## CPP11/14 Features
#

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for cxx_auto_type cxx_nullptr cxx_override cxx_final cxx_deleted_functions cxx_defaulted_functions)

#
## copy resources to binary
#

# we don't want to copy if we're building in the source dir
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/media/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/media/")
endif()
