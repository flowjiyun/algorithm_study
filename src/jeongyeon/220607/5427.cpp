#include <iostream>
#include <queue>
/*
using namespace std;

string board[1002];
int vis[1002][1002];
int fire[1002][1002];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> board[i];
		}
		for (int i = 0; i < h; i++) {
			fill(vis[i], vis[i] + w, -1);
			fill(fire[i], fire[i] + w, -1);
		}
		queue<pair<int, int>> ji;
		queue<pair<int, int>> fi;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '@') {
					ji.push({ i,j });
					vis[i][j] = 0;
				}
				else if (board[i][j] == '*') {
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
				if (nx < 0 || ny < 0 || h <= nx || w <= ny)
					continue;
				if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
					continue;
				fire[nx][ny] = fire[cur.first][cur.second] + 1;
				fi.push({ nx,ny });
			}
		}
		bool check = 0;
		while (!ji.empty()) {
			pair<int, int> cur = ji.front(); ji.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || h <= nx || w <= ny) {
					cout << vis[cur.first][cur.second] + 1 << '\n';
					check = 1;
					break;
				}
				if (vis[nx][ny] >= 0 || board[nx][ny] == '#')
					continue;
				if (fire[nx][ny] != -1 && vis[cur.first][cur.second] + 1 >= fire[nx][ny])
					continue;
				vis[nx][ny] = vis[cur.first][cur.second] + 1;
				ji.push({ nx,ny });
			}
			if (check) break;
		}
		if(!check) cout << "IMPOSSIBLE" << '\n';
	}
}
*/