#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int T, n;

int arr[100005];
int state[100005];

void run(int x)
{
    int cur = x;
    while (1)
    {
        state[cur] = x;
        cur = arr[cur];
        if (state[cur] == x)
        {

            while (state[cur] != -1)
            {
                state[cur] = -1;
                cur = arr[cur];
            }
            return ;
        }
        else if (state[cur] != 0)
            return ;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        fill (state + 1, state + n + 1, 0); // initialize the state as value of zero
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 1; i <= n; i++)
        {
            if (state[i] == 0)      // if you didn't visited
                run(i);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (state[i] != -1)
                cnt++;
        }
        cout << cnt << '\n';
    }
}