#include <string>
#include <iostream>

using std::cout; using std::endl;

class HasPtr 
{
    public:
        HasPtr& operator=(HasPtr);
        HasPtr& operator=(HasPtr&&);
        ~HasPtr() { delete ps; }
        std::string *ps;
        int i;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "executed" << endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this; 
}

HasPtr& HasPtr::operator=(HasPtr&& rhs) 
{
    if (this != &rhs) 
    {
        delete ps;
        ps = std::move(rhs.ps);
        rhs.ps = nullptr;
        i = rhs.i;
    }
    return *this;
}

int main() 
{
    HasPtr p1;
    p1.i = 1;
    p1.ps = new std::string("test");

    HasPtr p2;
    p2.i = 2;
    p2.ps = new std::string("test2");

    p1 = std::move(p2);
    *p1.ps;

    p2 = p1;
    *p2.ps;
    *p1.ps;

}
