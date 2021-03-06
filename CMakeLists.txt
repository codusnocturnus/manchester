cmake_minimum_required(VERSION 3.17)
# MUST be done before call to 'project'
get_cmake_property(vars CACHE_VARIABLES)
foreach(var ${vars})
  get_property(currentHelpString CACHE "${var}" PROPERTY HELPSTRING)
    if("${currentHelpString}" MATCHES "No help, variable specified on the command line." OR "${currentHelpString}" STREQUAL "")
        # message("${var} = [${${var}}]  --  ${currentHelpString}") # uncomment to see the variables being processed
        list(APPEND CL_ARGS "-D${var}=${${var}}")
    endif()
endforeach()

list(APPEND
    CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake
)

project(top
    LANGUAGES CXX
)

set(EXTERNAL_VCPKG_DIR "" CACHE STRING "Allows the project to use an existing external vcpkg instance.")
include(vcpkg_utilities)
get_vcpkg(${EXTERNAL_VCPKG_DIR})
vcpkg_packagefile("${CMAKE_CURRENT_LIST_DIR}/vcpkgs.txt")

include(ExternalProject)
set_property(DIRECTORY
    PROPERTY
        EP_BASE hello
)
ExternalProject_Add(hello
    DEPENDS ${VCPKG_DEPENDENCIES}
    SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/hello
    DOWNLOAD_COMMAND ""
    INSTALL_COMMAND ""
    BUILD_ALWAYS TRUE
    CMAKE_ARGS ${CL_ARGS};
               --no-warn-unused-cli;
               -DCMAKE_TOOLCHAIN_FILE=${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake
)

set_property(DIRECTORY
    PROPERTY
        EP_BASE tests
)
include(CTest)
ExternalProject_Add(tests
    DEPENDS ${VCPKG_DEPENDENCIES}
    SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/tests
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/tests
    DOWNLOAD_COMMAND ""
    INSTALL_COMMAND ""
    TEST_COMMAND "ctest"
    BUILD_ALWAYS TRUE
    CMAKE_ARGS ${CL_ARGS};
               --no-warn-unused-cli;
               -DMANCHESTER_ROOT=${CMAKE_CURRENT_SOURCE_DIR}
               -DCMAKE_TOOLCHAIN_FILE=${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake
)
