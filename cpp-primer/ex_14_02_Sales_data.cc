#include <iostream>
#include <string>

using std::cout, std::endl, std::cin, std::string, std::istream, std::ostream;

class Sales_data 
{
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend string operator+(const Sales_data&, const Sales_data&);
    
public:
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &is) { is >> *this; }
    
    Sales_data& operator+=(const Sales_data&);
    
    string isbn() const { return bookNo; }
    double avg_price() const { return units_sold ? revenue / units_sold : 0; }
    Sales_data& combine(const Sales_data&);
    
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream& operator>>(istream&, Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
string operator+(const Sales_data&, const Sales_data&);

int main()
{
    Sales_data s;
    return 0;
}
