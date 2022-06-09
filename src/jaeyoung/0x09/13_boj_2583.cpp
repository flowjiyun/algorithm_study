#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int board[102][102];
int vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k; // m은 행, n은 열, k는 개수

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    while(k--)
    {
        int x, y, xx, yy; // x는 열, y는 행
        cin >> x >> y >> xx >> yy;
        
        for (int i = y; i < yy; i++)
            for (int j = x; j < xx; j++)
                board[i][j] = 1;
    }

    int cnt = 0;
    vector<int> area;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] || vis[i][j])
                continue;
            vis[i][j] = 1;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            cnt++;
            int num = 0;
            while(!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                num++;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (vis[nx][ny] || board[nx][ny])
                        continue; 
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            area.push_back(num);
        }
    }
    sort(area.begin(), area.end());

    cout << cnt << '\n';
    for (auto c : area)
        cout << c << ' ';
}
