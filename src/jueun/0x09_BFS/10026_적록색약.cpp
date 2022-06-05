#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int n, r, g, b, rg;
string str;

int arr[101][101];
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int color, int x, int y)
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

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (visited[nx][ny] || arr[nx][ny] != color)
                continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

void bfs_rg(int x, int y)
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

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (visited[nx][ny] || arr[nx][ny] == 3)
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

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        fill(visited[i], visited[i] + n, false);

        for (int j = 0; j < n; j++)
        {
            if (str[j] == 'R')
                arr[i][j] = 1;
            else if (str[j] == 'G')
                arr[i][j] = 2;
            else
                arr[i][j] = 3;
        }
    }

    r = 0;
    g = 0;
    b = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && arr[i][j] == 1)
            {
                r++;
                bfs(1, i, j);
            }
            else if (!visited[i][j] && arr[i][j] == 2)
            {
                g++;
                bfs(2, i, j);
            }
            else if (!visited[i][j] && arr[i][j] == 3)
            {
                b++;
                bfs(3, i, j);
            }
        }
    }

    rg = 0;

    for (int i = 0; i < n; i++)
        fill(visited[i], visited[i] + n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i][j] == 1 || arr[i][j] == 2) && !visited[i][j])
            {
                rg++;
                bfs_rg(i, j);
            }
        }
    }

    cout << r + g + b << " " << rg + b;
    return 0;
}
