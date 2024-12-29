#include "googletest/googletest/include/gtest/gtest.h"
#include "alloc.h"

TEST(memory_allocation, first_allocation)
{
  Allocator alloc_1;
  alloc_1.makeAllocator(100);
  ASSERT_EQ(alloc_1.alloc_size, 100);
  ASSERT_TRUE(alloc_1.offset == alloc_1.base_pointer);
}

TEST(memory_allocation, second_allocation)
{
  Allocator alloc_1;
  alloc_1.makeAllocator(100);
  alloc_1.makeAllocator(10);
  ASSERT_EQ(alloc_1.alloc_size, 10);
  ASSERT_TRUE(alloc_1.offset == alloc_1.base_pointer);
}

TEST(memory_allocation, creating_array)
{
  char* ptr_1;
  char* ptr_2;
  char* ptr_all;
  Allocator alloc_1;

  alloc_1.makeAllocator(100);
  ptr_1 = alloc_1.alloc(10);
  ptr_2 = alloc_1.alloc(10);

  for (int i = 0; i < 10; i++)
  {
    *(ptr_1 + i) = 1;
  }
  for (int i = 0; i < 10; i++)
  {
    *(ptr_2 + i) = 2;
  }

  ASSERT_FALSE(ptr_1 == ptr_2);

  ptr_all = alloc_1.base_pointer;
  for (int i = 0; i < 10; i++)
  {
    ASSERT_EQ(*ptr_all, 1);
    ptr_all++;
  }
  for (int i = 0; i < 10; i++)
  {
    ASSERT_EQ(*ptr_all, 2);
    ptr_all++;
  }
}

TEST(memory_allocation, exceeding_maximum_size)
{
  Allocator alloc_1;
  char* ptr_1;

  alloc_1.makeAllocator(10);
  alloc_1.alloc(5);
  ptr_1 = alloc_1.alloc(10);

  ASSERT_TRUE(ptr_1 == nullptr);
}

TEST(memory_allocation, reset_memory)
{
  Allocator alloc_1;

  alloc_1.makeAllocator(100);
  alloc_1.alloc(20);
  alloc_1.alloc(10);
  ASSERT_FALSE(alloc_1.offset == alloc_1.base_pointer);

  alloc_1.reset();
  ASSERT_TRUE(alloc_1.offset == alloc_1.base_pointer);
}