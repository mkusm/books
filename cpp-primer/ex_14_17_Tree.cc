#include <iostream>

using std::ostream, std::istream;

class Tree
{
    friend ostream& operator<<(ostream&, const Tree&);
    friend istream& operator>>(istream&, Tree&);
    friend bool operator==(Tree&, Tree&);
    friend bool operator!=(Tree&, Tree&);
public:
    Tree(double h = 0, double w = 0, int b = 0): height(h), width(w), branches(b) { }
private:
    double height;
    double width;
    int branches;
};

ostream& operator<<(ostream &os, const Tree &t)
{
    os << "Height: " << t.height << ", width: " << t.width << ", branches: " << t.branches;
    return os;
}

bool operator==(Tree &lhs, Tree &rhs)
{
    return lhs.height == rhs.height && lhs.width == rhs.width && lhs.branches == rhs.branches;
}

bool operator!=(Tree &lhs, Tree &rhs)
{
    return !(lhs == rhs);
}
