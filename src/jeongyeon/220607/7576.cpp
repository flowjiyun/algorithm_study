#include <iostream>
#include <queue>
/*
using namespace std;

int board[1001][1001];
int vis[1001][1001];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push({ i,j });
			if (board[i][j] == 0)
				vis[i][j] = -1;
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || n <= nx || m <= ny)
				continue;
			if (vis[nx][ny]>=0)
				continue;
			vis[nx][ny] = vis[cur.first][cur.second]+1;
			q.push({ nx,ny });
		}
	}
	int day = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == -1) {
				cout << -1;
				return 0;
			}
			day = max(day, vis[i][j]);
		}
	}
	cout << day;
}
*/