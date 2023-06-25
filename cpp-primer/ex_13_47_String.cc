#include <algorithm>
#include <iostream>
#include <memory>

class String 
{
  public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const String&);
    String(const char[]);
    String& operator=(const String&);
    ~String();
    size_t size() const { return first_free - elements; }
    char* begin() const { return elements; }
    char* end() const { return first_free; }
  private:
    static std::allocator<char> alloc;
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    char* elements;
    char* first_free;
    char* cap;
};

std::allocator<char> String::alloc;

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e) 
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

String::String(const char c_arr[]) 
{
    const char* array_begin = c_arr;
    const char* array_end = c_arr;
    while (*array_end != '\0') ++array_end;
    auto newdata = alloc_n_copy(array_begin, array_end);
    elements = newdata.first;
    first_free = cap = newdata.second;
}


String::String(const String& s) 
{
    std::cout << "Copy constructor used" << std::endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String& String::operator=(const String& rhs) 
{
    std::cout << "Copy-assignment operator used" << std::endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

String::~String() 
{
    free();
}

void String::free() 
{
    if (elements) 
    {
        std::for_each(elements, first_free, [](char &s) { alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}


std::ostream &operator<<(std::ostream &os, const String &string) 
{
    for (auto it = string.begin(); it != string.end(); ++it) 
    {
        os << *it;
    }
    return os;
}
