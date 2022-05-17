#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a;
    long long b;
    long long sum;

    cin >> a >> b;
    if (a > b)
    {
        sum = a;
        a = b;
        b = sum;
    }
    sum = b - a - 1;
    if (sum == 0 || sum == 1)
        cout << '0';
    else 
    {
        cout << sum << '\n';
        while (a < b - 1)
            cout << ++a << ' ';
    }
}

