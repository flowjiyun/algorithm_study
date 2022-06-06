#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int board[101][101][101];
int dist[101][101][101];
int m, n, h;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int,int,int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					q.push({i,j,k});
				if (board[i][j][k] == 0)
					dist[i][j][k] = -1;
			}
		}
	}
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		int curx, cury, curz;
		tie(curx, cury, curz) = cur;
		for (int dir = 0; dir < 6; dir++)
		{
			int nx = curx + dx[dir];
			int ny = cury + dy[dir];
			int nz = curz + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
				continue;
			if (dist[nx][ny][nz] >= 0)
				continue;
			dist[nx][ny][nz] = dist[curx][cury][curz] + 1;
			q.push({nx,ny,nz});
		}
	}
	int ans = 0;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dist[i][j][k] == -1)
				{
					cout << -1;
					return (0);
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
}
