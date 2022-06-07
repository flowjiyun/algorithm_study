#include <iostream>
#include <queue>
/*
using namespace std;

int board[301][301];
bool vis[301][301];
int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};
int n,x;
int main() {
	cin >> n;
	while (n--) {
		cin >> x;
		for (int i = 0; i < x; i++) {
			fill(board[i], board[i] + x, 0);
			fill(vis[i], vis[i]+x, 0);
		}
		int start_x, start_y, end_x,end_y;
		cin >> start_x >> start_y >> end_x >> end_y;
		queue<pair<int, int>> q;
		q.push({ start_x,start_y });
		vis[start_x][start_y] = 1;
		int ans = 0;
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || x <= nx || x <= ny) continue;
				if (vis[nx][ny]) continue;
				q.push({ nx,ny });
				vis[nx][ny] = 1;
				board[nx][ny] = board[cur.first][cur.second] + 1;
			}
		}
		cout << board[end_x][end_y] << '\n';
	}
}
*/