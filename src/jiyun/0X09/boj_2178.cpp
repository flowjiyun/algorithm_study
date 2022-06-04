#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};

int dis[100][100];
string board[100];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int m;
    queue<pair<int, int>> Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dis[i][j] = -1;
        }
    }
    dis[0][0] = 0;
    Q.push({0, 0});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dis[nx][ny] != -1 || board[nx][ny] != '1')
                continue;
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    cout << dis[n - 1][m - 1] + 1;
    return (0);
}

