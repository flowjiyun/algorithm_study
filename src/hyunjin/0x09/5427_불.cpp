#include <iostream>
#include <queue>
using namespace std;
char building[1005][1005];
int fused[1005][1005];
int sused[1005][1005];
#define Y first
#define X second

int main()
{
	int test, by, bx;
	int dy[4] = { -1,0,0,1 };
	int dx[4] = { 0,-1,1,0 };

	cin >> test;
	for (int t = 0; t < test; t++) {
		// setting
		queue<pair<int, int>> fire,s;
		cin >> bx >> by;
		for (int y = 0; y < by; y++) {
			fill(fused[y], fused[y] + bx, -1);
			fill(sused[y], sused[y] + bx, -1);
		}
		
		// input
		string str;
		for (int y = 0; y < by; y++) {
			cin >> str;
			for (int x = 0; x < bx; x++) {
				building[y][x] = str[x];
				if (str[x] == '*') {
					fire.push({ y,x });
					fused[y][x] = 0;
				}
				else if (str[x] == '@') {
					s.push({ y,x });
					sused[y][x] = 0;
				}
			}
		}

		// bfs - fire
		while (!fire.empty()) {
			pair<int, int> cur = fire.front();
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cur.Y + dy[i];
				int nx = cur.X + dx[i];

				if (ny < 0 || ny >= by || nx < 0 || nx >= bx) continue;
				if (building[ny][nx] == '#' || fused[ny][nx] != -1) continue;
				fused[ny][nx] = fused[cur.Y][cur.X] + 1;
				fire.push({ ny,nx });
			}
		}

		// bfs - @
		int flag = 1;
		while (flag && !s.empty()) {
			pair<int, int> cur = s.front();
			s.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cur.Y + dy[i];
				int nx = cur.X + dx[i];

				if (ny < 0 || ny >= by || nx < 0 || nx >= bx) {
					cout << sused[cur.Y][cur.X] + 1 << "\n";
					flag = 0;
					break;
				}
				if (building[ny][nx] == '#' || sused[ny][nx] != -1) continue;
				if (fused[ny][nx] != -1 && fused[ny][nx] <= sused[cur.Y][cur.X] + 1) continue;

				sused[ny][nx] = sused[cur.Y][cur.X] + 1;
				s.push({ ny, nx });
			}
		}
		if (flag) cout << "IMPOSSIBLE\n";

	}
}
