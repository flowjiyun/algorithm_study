#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int n, m, cnt;
int arr[1001][1001];
int visited[1001][1001][2];

string str;
queue<pair<pair<int, int>, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs()
{
    visited[0][0][1] = 1;
    q.push({{0, 0}, 1});

    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();

        q.pop();

        if (p.first.first == n - 1 && p.first.second == m - 1)
            return visited[n - 1][m - 1][p.second];

        for (int i = 0; i < 4; i++)
        {
            int nx = p.first.first + dx[i];
            int ny = p.first.second + dy[i];
            int z = p.second;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny][z])
                continue;

            if (z && arr[nx][ny] == 1)
            {
                q.push({{nx, ny}, 0});
                visited[nx][ny][0] = visited[p.first.first][p.first.second][z] + 1;
            }

            if (arr[nx][ny] == 0)
            {
                q.push({{nx, ny}, z});
                visited[nx][ny][z] = visited[p.first.first][p.first.second][z] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    cout << bfs();

    return 0;
}
