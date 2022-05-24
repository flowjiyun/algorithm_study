#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int ans;
    cin >> a >> b >> c;
    
    if (a == b && a == c)
    {
        cout << 10000 + b * 1000;
    }
    else if (a == b || b == c || a == c)
    {
        if (a == b)
            cout << 1000 + a * 100;
        if (b == c)
            cout << 1000 + b * 100;
        if (a == c)
            cout << 1000 + a * 100;
    }
    else
    {
        cout << max(max(a, b), c) * 100;
    }
    return (0);
}