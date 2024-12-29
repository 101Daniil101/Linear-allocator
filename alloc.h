class Allocator
{
public:
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator();

//Оставил публиычными только, чтобы проверить тесты в файле test.cpp
    char* base_pointer = nullptr;
    size_t alloc_size;
    char* offset;
};