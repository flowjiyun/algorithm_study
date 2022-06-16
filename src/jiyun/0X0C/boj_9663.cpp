#include <iostream>

using namespace std;
int issued_col[27];
int issued_diag1[27];
int issued_diag2[27];

int ans = 0;
int n;
// 함수 인자로 퀸을 놓을 행을 받는다
void solve(int cur)
{
    if (cur == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (issued_col[i] || issued_diag1[cur + i] || issued_diag2[cur - i + n - 1])
            continue;
        issued_col[i] = 1;
        issued_diag1[cur + i] = 1;
        issued_diag2[cur - i + n - 1] = 1;
        solve(cur + 1);
        issued_col[i] = 0;
        issued_diag1[cur + i] = 0;
        issued_diag2[cur - i + n - 1] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve(0);
    cout << ans;
    return (0);
}