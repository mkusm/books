#include <iostream>

using std::ostream, std::istream;

class Tree
{
    friend ostream& operator<<(ostream& os, const Tree& t);
    friend istream& operator>>(istream& is, Tree& t);
public:
    Tree(double h = 0, double w = 0, int b = 0): height(h), width(w), branches(b) { }
private:
    double height;
    double width;
    int branches;
};

ostream& operator<<(ostream& os, const Tree& t)
{
    os << "Height: " << t.height << ", width: " << t.width << ", branches: " << t.branches;
    return os;
}

int main()
{
    Tree t(10, 5, 3);
    std::cout << t << std::endl;
    return 0;
}
