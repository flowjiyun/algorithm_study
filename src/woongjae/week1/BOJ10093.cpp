#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b;
    long long tmp;
    int cnt;

    cnt = 0;
    cin >> a >> b;
    if (a > b)
        swap (a, b);
    if (a <= b)
    {
        tmp = a;
        while (++tmp < b)
            cnt++;
        cout << cnt;
        cout << "\n";
        while(++a < b)
            cout << a << " ";
    }
    return (0);
}