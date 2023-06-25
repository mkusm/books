#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

using std::initializer_list, std::string, std::vector, std::shared_ptr, std::make_shared, std::weak_ptr;
using vpointer = shared_ptr<vector<string>>;

class StrBlobPtr;

class StrBlob {
        friend StrBlobPtr;
        friend bool operator==(const StrBlob&, const StrBlob&);
        friend bool operator!=(const StrBlob&, const StrBlob&);
    public:
        typedef vector<string>::size_type size_type;
        StrBlob(): data(make_shared<vector<string>>()) { }
        StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const string &t) {data->push_back(t);}
        void pop_back();
        string& front();
        string& back();
        string& front() const;
        string& back() const;
        StrBlobPtr begin();
        StrBlobPtr end();
    private:
        vpointer data;
        void check(size_type i, const string &msg) const;
};

class StrBlobPtr {
        friend operator==(const StrBlobPtr&, const StrBlobPtr&);
        friend operator!=(const StrBlobPtr&, const StrBlobPtr&);
    public:
        StrBlobPtr(): curr(0) { }
        StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
        string& deref() const;
        StrBlobPtr& incr();
    private:
        void check(size_t, const string&) const;
        weak_ptr<vector<string>> wptr;
        std::size_t curr;
};

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
    return *lhs.data == *rhs.data
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
    return !(lhs == rhs)
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return *lhs.curr == *rhs.curr
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return !(lhs == rhs)
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

vpointer StrBlobPtr::check(std::size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
