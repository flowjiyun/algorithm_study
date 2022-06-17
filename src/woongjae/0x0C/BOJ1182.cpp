#include <bits/stdc++.h>
using namespace std;
int n, s;
int arr[20];
int cnt = 0;

void func(int cur, int tot)
{
    if (cur == n)
    {
        if (tot == s)
            cnt++;
        return ;
    }
    func (cur + 1, tot);
    func (cur + 1, tot + arr[cur]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < 20; i++)
        cin >> arr[i];
    func (0, 0);
    if (s == 0)
        cnt--;
    cout << cnt;
}