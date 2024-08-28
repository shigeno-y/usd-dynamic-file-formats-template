include(FetchContent)

if(POLICY CMP0069)
  cmake_policy(SET CMP0069 NEW)
endif()

if(POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.14.1
  FIND_PACKAGE_ARGS)
FetchContent_MakeAvailable(spdlog)
