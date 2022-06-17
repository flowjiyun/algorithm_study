#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[9];
bool visited[9];

void func(int num, int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            func(i + 1,cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(1, 0);
}