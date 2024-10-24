# =============================================================================
# Copyright (c) 2024, NVIDIA CORPORATION.
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except
# in compliance with the License. You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under the License
# is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
# or implied. See the License for the specific language governing permissions and limitations under
# the License.
# =============================================================================

cmake_minimum_required(VERSION 3.26.4 FATAL_ERROR)

include(../../rapids_config.cmake)

include(rapids-cuda)
rapids_cuda_init_architectures(libraft-python)

project(
  libraft-python
  VERSION "${RAPIDS_VERSION}"
  LANGUAGES CXX CUDA
)

# Check if raft is already available. If so, it is the user's responsibility to ensure that the
# CMake package is also available at build time of the Python raft package.
find_package(raft "${RAPIDS_VERSION}")

if(raft_FOUND)
  return()
endif()

unset(raft_FOUND)

set(BUILD_TESTS OFF)
set(BUILD_PRIMS_BENCH OFF)
set(BUILD_ANN_BENCH OFF)
set(RAFT_COMPILE_LIBRARY ON)
set(RAFT_COMPILE_DYNAMIC_ONLY ON)
set(CUDA_STATIC_RUNTIME ON)

add_subdirectory(../../cpp raft-cpp)
