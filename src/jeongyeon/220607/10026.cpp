#include <iostream>
#include <string>
/*
using namespace std;

string board[101];
int vis[101][101];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || n <= nx || n <= ny)
			continue;
		if (vis[nx][ny] == 0 && board[nx][ny] == board[x][y]) {
			vis[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				num++;
				vis[i][j] = 1;
				dfs(i, j);
			}
		}
	}
	cout << num << " ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';

			vis[i][j] = 0;
		}
	}
	int num2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				num2++;
				vis[i][j] = 1;
				dfs(i, j);
			}
		}
	}
	cout << num2;
}
*/