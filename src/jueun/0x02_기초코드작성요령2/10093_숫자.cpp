#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, cnt;

    cin >> a >> b;

    if (a > b)
    {
        long long tmp = a;
        a = b;
        b = tmp;
    }

    cnt = b - a;
    if (cnt)
    {
        cout << cnt - 1 << "\n";
        for (long long i = a + 1; i < b; i++)
            cout << i << " ";
    }
    else
        cout << 0;

    return 0;
}