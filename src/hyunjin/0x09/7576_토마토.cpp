#include <iostream>
#include <queue>
using namespace std;
#define Y first
#define X second
int map[1005][1005];
int used[1005][1005];

int main()
{
	queue<pair<int, int>> q;

	int m, n;
	cin >> m >> n;
	int flag = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			if (map[y][x] == 0) flag = 1;
			if (map[y][x] == 1) {
				q.push({ y,x });
				used[y][x] = 1;
			}
		}
	}
	if (flag == 0) {
		cout << 0;
		return (0);
	}

	int dy[4] = { -1, 0, 0, 1 };
	int dx[4] = { 0, -1, 1, 0 };

	int max = 0, cnt = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (map[ny][nx] != 0 || used[ny][nx] != 0) continue;
			q.push({ ny,nx });
			cnt = used[cur.Y][cur.X] + 1;
			used[ny][nx] = cnt;
		}
	}
	if (max < cnt) max = cnt;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map[y][x] == 0 && used[y][x] == 0) {
				cout << -1;
				return (0);
			}
		}
	}
	cout << max - 1;
}
