#include <vector>
#include <iostream>

using std::vector, std::cout, std::endl;
using Iter = vector<int>::iterator;

void print(Iter beg, Iter end)
{
    if (beg != end)
    {
#ifndef NDEBUG
        cout << endl << __TIME__ << " " << "DEBUG: vector size is " << end - beg << endl;
#endif
        cout << *beg << " ";
        print(++beg, end);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 5, 8, 13, 21};
    print(v.begin(), v.end());
    return 0;
}
