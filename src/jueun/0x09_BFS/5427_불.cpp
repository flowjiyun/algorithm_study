#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int n, m;
int fire[1001][1001];
int arr[1001][1001];
string str[1001];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (str[i][j] == '*')
            {
                q1.push(make_pair(i, j));
                fire[i][j] = 0;
            }

            if (str[i][j] == '@')
            {
                q2.push(make_pair(i, j));
                arr[i][j] = 0;
            }
        }
    }

    while (!q1.empty())
    {
        int xx = q1.front().first;
        int yy = q1.front().second;

        q1.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || n <= nx || m <= ny)
                continue;
            if (fire[nx][ny] >= 0 || str[nx][ny] == '#')
                continue;
            fire[nx][ny] = fire[xx][yy] + 1;
            q1.push(make_pair(nx, ny));
        }
    }

    while (!q2.empty())
    {
        int xx = q2.front().first;
        int yy = q2.front().second;

        q2.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || n <= nx || m <= ny)
            {
                cout << arr[xx][yy] + 1 << "\n";
                return true;
            }
            if (arr[nx][ny] >= 0 || str[nx][ny] == '#')
                continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= arr[xx][yy] + 1)
                continue;
            arr[nx][ny] = arr[xx][yy] + 1;
            q2.push(make_pair(nx, ny));
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        cin >> m >> n;

        while (!q1.empty())
            q1.pop();
        while (!q2.empty())
            q2.pop();

        for (int i = 0; i < n; i++)
        {
            fill(fire[i], fire[i] + m, -1);
            fill(arr[i], arr[i] + m, -1);
            cin >> str[i];
        }

        if (!bfs())
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}
