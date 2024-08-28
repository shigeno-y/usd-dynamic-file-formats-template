# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.27)

project(usdDynamicFileFormatTemplate LANGUAGES CXX)

configure_file("${PROJECT_SOURCE_DIR}/template.json"
               "${PROJECT_BINARY_DIR}/template.json.tmp" @ONLY)
file(READ "${PROJECT_BINARY_DIR}/template.json.tmp" PLUGINFO_TEMPLATE)
file(
  GENERATE
  OUTPUT "${PROJECT_BINARY_DIR}/template.json"
  CONTENT ${PLUGINFO_TEMPLATE})

add_library(${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME} PRIVATE include/body.hpp src/body.cpp)
target_include_directories(
  ${PROJECT_NAME} PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

target_compile_definitions(${PROJECT_NAME}
                           PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:NOMINMAX>")

target_compile_options(
  ${PROJECT_NAME} PRIVATE "$<$<C_COMPILER_ID:MSVC>:/Zc:inline->"
                          "$<$<CXX_COMPILER_ID:MSVC>:/Zc:inline->")

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_CXX_STANDARD_REQUIRED ON
                                                 CMAKE_CXX_EXTENSIONS OFF)

find_package(spdlog REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

find_package(pxr CONFIG REQUIRED)
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE tf
          gf
          sdf
          usd
          usdGeom
          ar
          arch
          js
          vt)

if(APPLE)
  install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION plugin/usd
    ARCHIVE DESTINATION plugin/usd
    LIBRARY DESTINATION plugin/usd
    RESOURCE)
else()
  install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION plugin/usd
    LIBRARY DESTINATION plugin/usd
    RESOURCE)
endif()
install(
  FILES "${PROJECT_BINARY_DIR}/template.json"
  DESTINATION plugin/usd/${PROJECT_NAME}/resources
  RENAME plugInfo.json)
install(
  FILES "${PROJECT_SOURCE_DIR}/plugInfo.json"
  DESTINATION plugin/usd
  RENAME plugInfo.json)

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}-USD${usd_VERSION_STRING}-${GIT_HASH}")
include(CPack)
