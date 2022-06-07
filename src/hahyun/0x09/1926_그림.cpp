#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int mx = 0, num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 1 || vis[i][j])
                continue;
            num++;
            queue<pair<int, int> > q;
            vis[i][j] = 1;
            q.push(make_pair(i, j));

            int area = 0;
            while (!q.empty())
            {
                area++;
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << '\n'
         << mx;
}