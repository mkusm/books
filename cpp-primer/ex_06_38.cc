#include <iostream>
using std::cout, std::endl;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

int (&arrPtr(int i))[]
{
    return (i % 2) ? odd : even;
}

int main()
{
    int (&arr)[] = arrPtr(1);
    for (int i = 0; i != 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "-----------------" << endl;
    int (&arr2)[] = arrPtr(2);
    for (int i = 0; i != 5; i++)
        cout << arr2[i] << " ";
    cout << endl;
    return 0;
}
