#include <iostream>
using namespace std;

void func(int n)
{
    if (n == 0)
    {
        cout << n;
    }
    else
    {
        func(n - 1);
        cout << n << " ";
    }
}

int main()
{
    // for (int i = 0; i <= 5; i++)
    // {
    //     cout << i << " ";
    // }
    func(5);
    return 0;
}