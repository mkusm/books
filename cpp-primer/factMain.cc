#include "Chapter6.h"
#include <iostream>

using std::cin, std::cout, std::endl;

int main()
{
    cout << "Which factorial do you want?" << endl;
    int i;
    cin >> i;
    cout << "Factorial of " << i << " is " << fact(i) << endl;
}
