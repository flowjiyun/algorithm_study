#include<iostream>
using namespace std;
/*
int n;
string map[101];
int vis[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (vis[nx][ny] == 0 && map[nx][ny] == map[x][y]) {
			vis[nx][ny] = 1;
			dfs(nx, ny);
		}
	}


}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				ans++;
				vis[i][j] = 1;
				dfs(i, j);
			}
		}
	}
	cout << ans << " ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = 0;
		}
	}
	int ans2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				ans2++;
				vis[i][j] = 1;
				dfs(i, j);
			}
		}
	}
	cout << ans2;


	return 0;
}
*/