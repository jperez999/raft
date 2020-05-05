/*
 * Copyright (c) 2019-2020, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "allocator.hpp"
#include "buffer_base.hpp"

namespace raft {

/**
 * @brief RAII object owning a contiguous typed device buffer. The passed in
 *        allocator supports asynchronous allocation and deallocation so this
 *        can also be used for temporary memory
 *
 * @code{.cpp}
 * template<typename T>
 * void foo(const raft_handle& h, ..., cudaStream_t stream) {
 *     ...
 *     device_buffer<T> temp( h.getDeviceAllocator(), stream, 0 );
 *
 *     temp.resize(n, stream);
 *     kernelA<<<grid,block,0,stream>>>(...,temp.data(),...);
 *     kernelB<<<grid,block,0,stream>>>(...,temp.data(),...);
 *     temp.release(stream);
 * }
 * @endcode
 */
template <typename T>
using device_buffer = buffer_base<T, deviceAllocator>;

}  // namespace raft
