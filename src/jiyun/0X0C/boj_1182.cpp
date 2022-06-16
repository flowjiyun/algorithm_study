#include <iostream>

using namespace std;
int n, s;
int arr[20];
int cnt = 0;
void solve(int cur, int cur_sum)
{
    if (cur == n)
    {
        if (cur_sum == s)
            cnt++;
        return;
    }
    solve(cur + 1, cur_sum);
    solve(cur + 1, cur_sum + arr[cur]); 
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    solve(0, 0);
    if (s == 0)
        cout << cnt - 1;
    else
        cout << cnt; 
    return (0);
}