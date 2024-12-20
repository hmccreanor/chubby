cmake_minimum_required(VERSION 3.10)

project(chubby)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
set(ABSL_ENABLE_INSTALL ON)
FetchContent_Declare(
  absl
  GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
  GIT_TAG        origin/master
  OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(absl)

FetchContent_Declare(
  gRPC
  GIT_REPOSITORY https://github.com/grpc/grpc
  GIT_TAG        v1.68.2
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

add_executable(chubby src/main.cpp)
target_link_libraries(chubby grpc++)
