#include <iostream>
#include <string>

using std::cout, std::endl, std::cin, std::string, std::istream, std::ostream;

struct Sales_data;

istream& read(istream &is, Sales_data &item);
ostream& print(ostream &os, const Sales_data &item);

struct Sales_data {
    Sales_data(istream &is = cin) { read(is, *this); }
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }

    string isbn() const { return bookNo; }
    double avg_price() const { return units_sold ? revenue / units_sold : 0; }
    Sales_data& combine(const Sales_data&);
    
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream& read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}
