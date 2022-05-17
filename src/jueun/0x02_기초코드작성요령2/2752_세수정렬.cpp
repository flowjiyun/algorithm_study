#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;

    cin >> a >> b >> c;

    if (a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    if (a > c)
    {
        int tmp = a;
        a = c;
        c = tmp;
    }

    if (b > c)
    {
        int tmp = b;
        b = c;
        c = tmp;
    }

    cout << a << " " << b << " " << c;
    return 0;
}