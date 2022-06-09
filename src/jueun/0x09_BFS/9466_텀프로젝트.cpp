#include <iostream>

using namespace std;

int t, n, cnt;
int selected[100001];
int visited[100001];
int team[100001];

void dfs(int idx)
{
    if (visited[idx] == -1 || team[idx] == 1)
        return;

    if (visited[idx] == 0)
        visited[idx] = 1;
    else if (visited[idx] == 1)
    {
        team[idx] = 1;
        cnt++;
    }

    dfs(selected[idx]);
    visited[idx] = -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> selected[i];
            visited[i] = 0;
            team[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
        cout << n - cnt << "\n";
    }

    return 0;
}
