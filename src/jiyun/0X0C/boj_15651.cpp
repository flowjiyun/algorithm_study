#include <iostream>

using namespace std;
int n, m;
int arr[7];
void solve(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[k] = i;
        solve(k + 1);
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; 
    solve(0);
    return (0);
}