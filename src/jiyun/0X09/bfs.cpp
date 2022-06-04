#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
int board[502][502] = {};
bool vis[502][502];
int n = 7;
int m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    vis[0][0] = 1;
    Q.push({0, 0});

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // board의 범위를 벗어나면 다음 좌표로 이동
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            // 해당 위치를 이미 방문 했거나 방문할 곳이 아니라면 다음 좌표로 이동
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    return (0); 
}