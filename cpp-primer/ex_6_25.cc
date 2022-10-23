#include <iostream>
#include <cstring>

using std::cout, std::endl;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " arg1 arg2" << endl;
        return -1;
    }
    char concatenated[100];
    strcpy(concatenated, argv[1]);
    strcat(concatenated, argv[2]);
    cout << "Concatenated string: " << concatenated << endl;
    return 0;
}
