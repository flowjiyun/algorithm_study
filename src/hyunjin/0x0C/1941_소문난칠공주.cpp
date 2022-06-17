#include <iostream>
#include <queue>
using namespace std;
#define Y first
#define X second
char ipt[5][5];
int picked[25];
int cnt;

int morethan4() {
	int s = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (picked[y * 5 + x] && ipt[y][x] == 'S') s++;
		}
	}
	if (s >= 4) return (1);
	return(0);
}

int connected() {
	int dy[4] = { -1,0,0,1 };
	int dx[4] = { 0,-1,1,0 };
	int used[5][5];
	for (int i = 0; i < 5; i++)
		fill(used[i], used[i] + 5, 0);

	queue<pair<int, int>> q;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (picked[y * 5 + x] == 0) continue;

			int c = 1;
			q.push({ y,x });
			used[y][x] = 1;
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = cur.Y + dy[i];
					int nx = cur.X + dx[i];

					if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
					if (!picked[ny * 5 + nx] || used[ny][nx]) continue;
					c++;
					used[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
			if (c != 7) return (0);
			return (1);
		}
	}
}

void run(int lev, int start) {
	if (lev == 7) {
		if (morethan4() && connected()) {
			cnt++;
		}
		return;
	}

	for (int i = start; i < 25; i++) {
		picked[i] = 1;
		run(lev + 1, i + 1);
		picked[i] = 0;
	}
}

int main()
{
	string str;
	for (int y = 0; y < 5; y++) {
		cin >> str;
		for (int x = 0; x < 5; x++)
			ipt[y][x] = str[x];
	}

	run(0, 0);
	cout << cnt;
}
