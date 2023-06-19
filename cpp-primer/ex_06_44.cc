#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string s1 = "2137xd", s2 = "1337";
    cout << s1 << " is " << (isShorter(s1, s2) ? "shorter" : "longer") << " than " << s2 << endl;
    return 0;
}
