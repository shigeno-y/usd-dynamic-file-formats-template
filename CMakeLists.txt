# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.20)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(usd-dynamic-file-formats-template LANGUAGES CXX)

execute_process(
  COMMAND git -C ${CMAKE_SOURCE_DIR} rev-parse HEAD
  OUTPUT_VARIABLE GIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(
  COMMAND git -C ${CMAKE_SOURCE_DIR} rev-parse --abbrev-ref HEAD
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE)

include(${CMAKE_SOURCE_DIR}/cmake/dependencies.cmake)

add_compile_options(
  "$<$<C_COMPILER_ID:MSVC>:/MP>" "$<$<CXX_COMPILER_ID:MSVC>:/MP>"
  "$<$<C_COMPILER_ID:MSVC>:/utf-8>" "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include_directories(AFTER ${CMAKE_SOURCE_DIR}/common)

add_subdirectory(plugin)
