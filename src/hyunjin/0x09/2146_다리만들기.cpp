#include <iostream>
#include <queue>
using namespace std;

#define Y first
#define X second

int n;
int map[105][105];
int used[105][105];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
queue<pair<int, int>> q;

void group() {
	int num = 1;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 0 || used[y][x] == 1) continue;

			q.push({ y,x });
			map[y][x] = num;
			used[y][x] = 1;
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = cur.Y + dy[i];
					int nx = cur.X + dx[i];

					if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					if (map[ny][nx] == 0 || used[ny][nx] == 1) continue;
					q.push({ ny,nx });
					map[ny][nx] = num;
					used[ny][nx] = 1;
				}
			}
			num++;
		}
	}
	for (int y = 0; y < n; y++) {
		fill(used[y], used[y] + n, -1);
	}
}

int main()
{
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	group();

	int mini = 10000;
	int tar = -1;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 0 || used[y][x] != -1||map[y][x]<=tar) continue;
			
			for (int y = 0; y < n; y++)
				fill(used[y], used[y] + n, -1);
			q.push({ y,x });
			used[y][x] = 0;
			tar = map[y][x];
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = cur.Y + dy[i];
					int nx = cur.X + dx[i];

					if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					if (used[ny][nx] != -1) continue;
					if (used[cur.Y][cur.X] + 1 > mini) continue;
					if (map[ny][nx] != 0 && map[ny][nx] != tar) {
						if (used[cur.Y][cur.X] < mini) mini = used[cur.Y][cur.X];
						break;
					}

					if (map[ny][nx] == 0) {
						q.push({ ny,nx });
						used[ny][nx] = used[cur.Y][cur.X] + 1;
					}
					if (map[ny][nx] == tar) {
						q.push({ ny,nx });
						used[ny][nx] = 0;
					}
				}
			}
		}
	}

	cout << mini;
}
