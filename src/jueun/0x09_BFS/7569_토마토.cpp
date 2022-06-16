#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m, h, cnt;
int arr[101][101][101];
int visited[101][101][101];

queue<pair<pair<int, int>, int>> q;

int dy[6] = {-1, 1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> arr[i][j][k];

                if (arr[i][j][k] == 1)
                {
                    q.push({{i, j}, k});
                }
                if (arr[i][j][k] == 0)
                    visited[i][j][k] = -1;
            }
        }
    }

    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nz = p.first.first + dz[i];
            int nx = p.first.second + dx[i];
            int ny = p.second + dy[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)
                continue;
            if (visited[nz][nx][ny] >= 0)
                continue;
            visited[nz][nx][ny] = visited[p.first.first][p.first.second][p.second] + 1;
            q.push({{nz, nx}, ny});
        }
    }

    cnt = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (visited[i][j][k] == -1)
                {
                    cout << -1;
                    return 0;
                }

                if (visited[i][j][k] > cnt)
                    cnt = visited[i][j][k];
            }
        }
    }

    cout << cnt;

    return 0;
}
