#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int input[8];
int ans[8];
int issued[8];
void solve(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (k != 0 && input[i] < ans[k - 1])
            continue;
        if (issued[i])
            continue;
        ans[k] = input[i];
        issued[i] = 1;
        solve(k + 1);
        issued[i] = 0;
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);
    solve(0);
    return (0);
}