/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <stdlib.h>
#include <stdint.h>

#include <binder/MemoryBase.h>


namespace android {

// ---------------------------------------------------------------------------

#ifdef STE_HARDWARE
extern "C" void _ZN7android10MemoryBaseC2ERKNS_2spINS_11IMemoryHeapEEElj() __attribute__((alias("_ZN7android10MemoryBaseC1ERKNS_2spINS_11IMemoryHeapEEElj")));
#endif

MemoryBase::MemoryBase(const sp<IMemoryHeap>& heap,
        ssize_t offset, size_t size)
    : mSize(size), mOffset(offset), mHeap(heap)
{
}

sp<IMemoryHeap> MemoryBase::getMemory(ssize_t* offset, size_t* size) const
{
    if (offset) *offset = mOffset;
    if (size)   *size = mSize;
    return mHeap;
}

MemoryBase::~MemoryBase()
{
}

#ifdef STE_HARDWARE
sp<IMemoryHeap> android::MemoryBase::getMemory(long* offset, unsigned int* size) const
{
    ssize_t offset_o;
    size_t size_o;
    sp<IMemoryHeap> res;

    res = getMemory(&offset_o, & size_o);
    *offset = offset_o;
    *size = size_o;

    return res;
}
#endif

// ---------------------------------------------------------------------------
}; // namespace android
