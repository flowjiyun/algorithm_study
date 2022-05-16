#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a;
    int i;
    int result1;
    int result2;

    result1 = 0;

    result2 = 100;
    i = 0;
    while (i < 7)
    {
        cin >> a;
        if (a % 2 == 1)
        {
            result1 += a;
            result2 = min(a, result2);
        }
        i++;
    }
    if (!result1)
        cout << "-1";
    else
    {
    cout << result1 << "\n" << result2;
    }

    return (0);
}