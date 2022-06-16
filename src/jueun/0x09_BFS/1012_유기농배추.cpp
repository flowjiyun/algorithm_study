#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int t, n, m, k, cnt;
int arr[51][51];
bool visited[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    queue<pair<int, int>> q;

    visited[x][y] = true;

    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny] || arr[nx][ny] == 0)
                continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k;

        int x, y;

        for (int i = 0; i < n; i++)
        {
            fill(visited[i], visited[i] + m, false);
            fill(arr[i], arr[i] + m, 0);
        }

        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            arr[x][y] = 1;
        }

        cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && arr[i][j] == 1)
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
