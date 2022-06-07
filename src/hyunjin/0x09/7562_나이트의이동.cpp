#include <iostream>
#include <queue>
using namespace std;
#define Y first
#define X second
int used[305][305];

int main()
{
	int test, n, ty, tx, gy, gx;
	int dy[8] = { -2,-2,-1,-1,1,1,2,2 };
	int dx[8] = { -1,1,-2,2,-2,2,-1,1 };

	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			fill(used[i], used[i] + n, -1);
		}
		cin >> ty >> tx >> gy >> gx;
		queue<pair<int, int>> q;
		q.push({ ty,tx });
		used[ty][tx] = 0;

		int flag = 1;
		if (ty == gy && tx == gx) {
			cout << 0 << "\n";
			continue;
		}
		while (!q.empty() && flag) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				int ny = cur.Y + dy[i];
				int nx = cur.X + dx[i];

				if (ny == gy && nx == gx) {
					cout << used[cur.Y][cur.X] + 1 << "\n";
					flag = 0;
				}
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (used[ny][nx] != -1) continue;

				used[ny][nx] = used[cur.Y][cur.X] + 1;
				q.push({ ny,nx });
			}
		}
	}
}
