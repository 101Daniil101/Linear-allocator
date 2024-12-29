#include <cstdlib>
#include "alloc.h"

void Allocator::makeAllocator(size_t maxSize)
{   
    if (!base_pointer)
    {
        delete[] (base_pointer);
    }
    base_pointer = new char[maxSize];
    if (!base_pointer)
    {
        exit(1);
    }
    offset = base_pointer;
    alloc_size = maxSize;
}

char* Allocator::alloc(size_t size)
{
    char* ptr;
    if (offset + size > base_pointer + alloc_size)
    {
        return nullptr;
    }
    ptr = offset;
    offset += size;
    return ptr;
}

void Allocator::reset()
{
    offset = base_pointer;
}

Allocator::~Allocator()
{
    delete[] (base_pointer);
}