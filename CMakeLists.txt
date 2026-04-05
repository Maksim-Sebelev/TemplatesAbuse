cmake_minimum_required(VERSION 3.28)

# =================================================================================================

project(TemplatesAbuse-n-prime
    LANGUAGES CXX
    VERSION 1.0
)

# =================================================================================================

if (NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
else()
  if (CMAKE_CXX_STANDARD LESS 20)
    message(FATAL_ERROR "CMAKE_CXX_STANDARD requires to be greater or equal than 20, but given ${CMAKE_CXX_STANDARD}")
  endif(CMAKE_CXX_STANDARD LESS 20)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# =================================================================================================

enable_testing()
include(CTest)

# =================================================================================================

add_subdirectory(${PROJECT_SOURCE_DIR}/n-prime)

# =================================================================================================
