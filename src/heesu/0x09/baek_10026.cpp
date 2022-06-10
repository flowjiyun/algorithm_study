#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second
char board[101][101];
bool vis[101][101];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	vis[x][y] = 1;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (vis[nx][ny] || board[x][y] != board[nx][ny])
				continue;
			vis[nx][ny] = 1;
			q.push({nx,ny});
		}
	}
}

int color_check()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j])
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	int color = color_check(); // 적록색약 아닌 사람
	
	// 적록색약인 사람을 구하기 위한 배열 초기화 
	for (int i = 0; i < n; i++)
		fill(vis[i], vis[i] + n, false);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'R')
				board[i][j] = 'G';
		}
	}
	int not_color = color_check();
	cout << color << " " << not_color;
}
