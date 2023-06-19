#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

class StrVec 
{
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec(StrVec&&);
    StrVec(initializer_list<string>);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t, const string&);
private:
    static allocator<string> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string* elements;
    string* first_free;
    string* cap;
};

allocator<string> StrVec::alloc;

void StrVec::push_back(const string& s) 
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) 
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

StrVec::StrVec(const StrVec& s) 
{
    std::cout << "Copy constructor used" << std::endl;   
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec&& s) 
{
    std::cout << "Move constructor used" << std::endl;   
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec::StrVec(initializer_list<string> il) 
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() 
{
    free();
}

void StrVec::free() 
{
    if (elements) {
        for_each(elements, first_free, [](string &s) {alloc.destroy(&s);});
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec& StrVec::operator=(const StrVec& rhs) 
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() 
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n) 
{
    if (n > capacity()) {
        auto newdata = alloc.allocate(n);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + n;
    }
}

void StrVec::resize(size_t n, const string& s) 
{
    if (n > size()) {
        if (n > capacity())
            reserve(n);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, s);
    } else if (n < size()) {
        while (first_free != elements + n)
            alloc.destroy(--first_free);
    }
}

int main()
{
    // allocate two elements using initializer list, size and capacity should be equal
    StrVec sv{"test", "this"};
    cout << "size: " << sv.size() << endl;
    cout << "capacity: " << sv.capacity() << endl;
    cout << "content: ";
    for (auto it = sv.begin(); it != sv.end(); ++it)
        cout << *it << ' ';
    cout << endl << endl;
    // allocate 8 more elements using resize, size and capacity should stay equal at 10
    sv.resize(10, "resize");
    cout << "size: " << sv.size() << endl;
    cout << "capacity: " << sv.capacity() << endl;
    cout << "content: ";
    for (auto it = sv.begin(); it != sv.end(); ++it)
        cout << *it << ' ';
    cout << endl << endl;
    // add 2 more elements using push_back, size should be 12, capacity should be 20
    sv.push_back("push");
    sv.push_back("back");
    cout << "size: " << sv.size() << endl;
    cout << "capacity: " << sv.capacity() << endl;
    cout << "content: ";
    for (auto p = sv.begin(); p != sv.end(); ++p)
        cout << *p << ' ';
    cout << endl;
    return 0;
}
