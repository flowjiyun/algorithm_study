#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[501][501];
int vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int,int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0 || vis[i][j])
				continue;
			cnt++;
			vis[i][j] = 1;
			q.push({i,j});
			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (vis[nx][ny] || board[nx][ny] == 0)
						continue;
					board[nx][ny] = cnt;
					vis[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
		}
	}


}
