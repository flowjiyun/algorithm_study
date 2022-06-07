#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dis[300][300];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, x, y, tx, ty;
    queue <pair<int, int >> Q;
  
    cin >> t;
    while (t--) 
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                dis[i][j] = -1;
        }
        cin >> x >> y;
        cin >> tx >> ty;
        dis[x][y] = 0;
        Q.push({x, y});
        while (!Q.empty()) 
        {
            auto cur = Q.front(); 
            Q.pop();
            for (int dir = 0; dir < 8; dir++) 
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (dis[nx][ny] >= 0)
                    continue;
                dis[nx][ny] = dis[cur.X][cur.Y] + 1;        
                Q.push({nx, ny});
            }
        }
        cout << dis[tx][ty] << '\n';
    }
    return (0);
}