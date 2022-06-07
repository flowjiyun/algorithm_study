#include <iostream>
#include <queue>
#include <tuple>
/*
using namespace std;

int board[101][101][101];
int vis[101][101][101];
int n, m, h;
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> h;
	queue<tuple<int, int,int>> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					q.push({i,j,k});
				if (board[i][j][k] == 0)
					vis[i][j][k] = -1;
			}
		}
	}
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = get<1>(cur) + dx[i];
			int ny = get<2>(cur) + dy[i];
			int nz = get<0>(cur) + dz[i];
			if (nx < 0 || ny < 0 || nz<0 || n <= nx || m <= ny || h<=nz)
				continue;
			if (vis[nz][nx][ny] >= 0)
				continue;
			vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nz,nx,ny});
		}
	}
	int day = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (vis[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				day = max(day, vis[i][j][k]);
			}
		}
	}
	cout << day;
}
*/