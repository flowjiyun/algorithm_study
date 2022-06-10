#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char board[1001][1001];
int vis[1001][1001][2]; // 0 벽 안깸, 1 벽깸 
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tuple<int,int,int>> q;

int bfs()
{
	vis[1][1][1] = 1;
	q.push({0,0,0});

	while (!q.empty())
	{
		int curx = get<0>(q.front());
		int cury = get<1>(q.front());
		int curz = get<2>(q.front());
		q.pop();
		if (curx == n - 1 && cury == m - 1) // 목표 도달
			return vis[curx][cury][curz];
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curx + dx[dir];
			int ny = cury + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			// 가려는 곳이 벽, 벽 부술 수 있음 
			if (board[nx][ny] == '1' && curz == 1)
			{
				q.push({nx,ny,curz - 1});
				vis[nx][ny][curz - 1] = vis[curx][cury][curz] + 1;
			}
			// 갈 수 있는 곳, 방문한 적 없음
			else if (board[nx][ny] == '0' && vis[nx][ny][curz] == 0)
			{
				q.push({nx,ny,curz});
				vis[nx][ny][curz] = vis[curx][cury][curz] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	cout << bfs();
}
