#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, cnt, res, sum, check;
int arr[501][501];
bool visited[501][501];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y)
{
    if (visited[x][y])
        return 0;

    visited[x][y] = true;
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    sum = 0;
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        sum++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || n <= nx || m <= ny)
                continue;
            if (visited[nx][ny] || !arr[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = false;
        }
    }

    cnt = 0;
    res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && arr[i][j])
            {
                check = bfs(i, j);
                cnt++;
                if (check > res)
                    res = check;
            }
        }
    }

    cout << cnt << "\n";
    cout << res;
    return 0;
}
