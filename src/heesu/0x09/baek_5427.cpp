#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간 
int dist2[1002][1002]; // 상근이의 이동 시간 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int w, h;

	cin >> t;
	while (t--)
	{
		bool check = false;
		queue<pair<int,int>> q1;
		queue<pair<int,int>> q2;

		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				dist1[i][j] = -1;
				dist2[i][j] = -1;
			}
		}
		for (int i = 0; i < h; i++)
			cin >> board[i];

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j] == '*')
				{
					q1.push({i,j});
					dist1[i][j] = 0;
				}
				if (board[i][j] == '@')
				{
					q2.push({i,j});
					dist2[i][j] = 0;
				}
			}
		}
		
		// 불에 대한 BFS
		while (!q1.empty())
		{
			auto cur = q1.front(); q1.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
					continue;
				dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
				q1.push({nx,ny});
			}
		}

		//상근이에 대한 BFS
		while (!q2.empty())
		{
			auto cur = q2.front(); q2.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					cout << dist2[cur.X][cur.Y] + 1 << '\n';
					check = true;
					break;
				}
				if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
					continue;
				if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
					continue;
				dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
				q2.push({nx,ny});
			}
			if (check) break;
		}
		if (!check)
			cout << "IMPOSSIBLE" << '\n';
	}
}
