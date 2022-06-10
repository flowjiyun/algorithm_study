#include <iostream>
#include <queue>
using namespace std;
int py, px;
int field[305][305];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

#define Y first
#define X second

void melt() {
	int temp[305][305] = { 0 };

	for (int y = 0; y < py; y++) {
		for (int x = 0; x < px; x++) {
			pair<int, int> cur = { y,x };

			if (field[y][x] == 0) continue;

			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = cur.Y + dy[i];
				int nx = cur.X + dx[i];

				if (ny < 0 || ny >= py || nx < 0 || nx >= px) continue;
				if (field[ny][nx] == 0) cnt++;
			}
			temp[y][x] = cnt;
		}
	}

	for (int y = 0; y < py; y++) {
		for (int x = 0; x < px; x++) {
			field[y][x] -= temp[y][x];
			if (field[y][x] < 0) field[y][x] = 0;
		}
	}
}

int is_separated() {
	int used[305][305] = { 0 };

	int flag = 0;
	queue<pair<int, int>> q;
	for (int y = 0; y < py; y++) {
		for (int x = 0; x < px; x++) {
			if (field[y][x] == 0 || used[y][x] != 0) continue;

			if (flag == 1) return (1);
			flag = 1;
			q.push({ y,x });
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = cur.Y + dy[i];
					int nx = cur.X + dx[i];

					if (ny < 0 || ny >= py || nx < 0 || nx >= px) continue;
					if (field[ny][nx] == 0 || used[ny][nx] != 0) continue;
					used[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
		}
	}

	if (flag == 0) return (0);
	if (flag == 1) return (-1);
}

int main()
{
	cin >> py >> px;
	for (int y = 0; y < py; y++) {
		for (int x = 0; x < px; x++) {
			cin >> field[y][x];
		}
	}

	int year = 0;
	while (true) {
		year++;
		melt();

		int ret = is_separated();
		if (ret == -1) continue;
		else if (ret == 0) cout << 0;
		else if (ret == 1) cout << year;

		break;
	}
}

