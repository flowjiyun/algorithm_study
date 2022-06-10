#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int hx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 

int board[200][200];
int vis[31][200][200];

int k, w, h;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<tuple<int, int, int>> Q;
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < w; k++)
                vis[i][j][k] = -1;
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> board[i][j];
    }

    vis[0][0][0] = 0;
    Q.push({0, 0, 0});
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        int cnt, x, y;
        tie(cnt, x, y) = cur;
        Q.pop();
        if (cnt < k + 1)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = x + hx[dir];
                int ny = y + hy[dir];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                if (board[nx][ny] == 1)
                    continue;
                if (vis[cnt + 1][nx][ny] >= 0)
                    continue;
                vis[cnt + 1][nx][ny] = vis[cnt][x][y] + 1;
                Q.push({cnt + 1, nx, ny});
            }
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + mx[dir];
            int ny = y + my[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (board[nx][ny] == 1)
                continue;
            if (vis[cnt][nx][ny] >= 0)
                continue;
            vis[cnt][nx][ny] = vis[cnt][x][y] + 1;
            Q.push({cnt, nx, ny});
        }
    }
    /*
    for (int i = 0; i < k + 1; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < w; k++)
                cout <<  vis[1][j][k] << ' ';
            cout << '\n';
        }
    }
    */
    int ans = 2100000000;

    for (int i = 0; i < k + 1; i++)
    {
        if (vis[i][h - 1][w - 1] != -1 && ans > vis[i][h - 1][w - 1])
            ans = vis[i][h - 1][w - 1];
    }
    if (ans == 2100000000)
        cout << -1;
    else
        cout << ans;

    return (0);
}