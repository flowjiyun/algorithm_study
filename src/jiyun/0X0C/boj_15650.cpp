#include <iostream>

using namespace std;
int n, m;
int issued[9];
int arr[8];
// 자연수 시작 값을 매개변수로 받는다
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
        if (k != 0 && i < arr[k - 1]) // 오름 차순 수열을 만들기 위한 조건
            continue;
        if (issued[i]) // 해당 자연수가 사용되었으면 다음 수 탐색
           continue; 
        arr[k] = i;
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
    solve(0);
    return (0);
}