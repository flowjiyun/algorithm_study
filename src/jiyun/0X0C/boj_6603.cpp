#include <iostream>

using namespace std;

int n;
int input[12];
int ans[12];

void solve(int index, int k)
{
    if (k == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = index; i < n; i++)
    {
        ans[k] = input[i];
        solve(index + 1, k + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        solve(0, 0);
        cout << '\n';
        for (int i = 0; i < 12; i++)
        {
            input[i] = 0;
            ans[i] = 0;
        }
    }
    return (0);
}