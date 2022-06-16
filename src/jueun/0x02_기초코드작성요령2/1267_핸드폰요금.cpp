#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, y, m;

    cin >> a;
    y = 0;
    m = 0;

    for (int i = 0; i < a; i++)
    {
        cin >> b;

        y += ((b / 30) + 1) * 10;
        m += ((b / 60) + 1) * 15;
    }

    if (y == m)
    {
        cout << "Y M " << y;
    }
    else if (y < m)
        cout << "Y " << y;
    else
        cout << "M " << m;

    return 0;
}