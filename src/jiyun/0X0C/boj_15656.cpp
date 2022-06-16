#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int input[7];
int ans[7];
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
        ans[k] = input[i];
        solve(k + 1);
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