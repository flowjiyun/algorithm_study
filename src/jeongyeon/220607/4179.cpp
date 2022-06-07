#include <iostream>
#include <queue>
/*
using namespace std;

string board[1002];
int vis[1002][1002];
int fire[1002][1002];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + m, -1);
		fill(fire[i],fire[i] + m, -1);
	}
	queue<pair<int, int>> ji;
	queue<pair<int, int>> fi;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'J') {
				ji.push({ i,j });
				vis[i][j] = 0;
			}
			else if (board[i][j] == 'F') {
				fi.push({ i,j });
				fire[i][j] = 0;
			}
		}
	}
	while (!fi.empty()) {
		pair<int, int> cur = fi.front(); fi.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || n <= nx || m <= ny)
				continue;
			if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			fire[nx][ny] = fire[cur.first][cur.second] + 1;
			fi.push({ nx,ny });
		}
	}
	while (!ji.empty()) {
		pair<int, int> cur = ji.front(); ji.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || n <= nx || m <= ny) {
				cout << vis[cur.first][cur.second] + 1;
				return 0;
			}
			if (vis[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if (fire[nx][ny] != -1 && vis[cur.first][cur.second] +1 >= fire[nx][ny])
				continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			ji.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}
*/