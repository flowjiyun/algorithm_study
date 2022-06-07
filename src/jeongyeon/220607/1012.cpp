#include <iostream>
#include <queue>
/*
using namespace std;

int board[51][51];
bool vis[51][51];
int n,m,k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int x, int y) {
	board[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || n <= nx || m <= ny)
			continue;
		if (board[nx][ny] == 0 || vis[nx][ny])
			continue;
		dfs(nx,ny);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int loop;
	cin >> loop;
	while (loop--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;
				num++;
				dfs(i, j);
			}
		}
		cout << num << '\n';
	}
}
*/