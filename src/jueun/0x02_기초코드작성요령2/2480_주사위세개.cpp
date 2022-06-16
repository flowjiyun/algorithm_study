#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, ans;

    cin >> n >> m >> k;

    ans = 0;

    if ((n == m) && (m == k))
        ans = 10000 + (n * 1000);
    else if (n == m)
        ans = 1000 + (n * 100);
    else if (m == k)
        ans = 1000 + (m * 100);
    else if (n == k)
        ans = 1000 + (k * 100);
    else
    {
        int max = n;
        if (max < m)
            max = m;
        if (max < k)
            max = k;
        ans = max * 100;
    }
    cout << ans;
    return 0;
}