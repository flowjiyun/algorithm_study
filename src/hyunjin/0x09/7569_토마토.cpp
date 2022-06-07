#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct s {
	int h, y, x;
};
int by, bx, bh;
int box[105][105][105];
int used[105][105][105];
queue<s> q;

int input() {
	int cnt = 0;

	cin >> bx >> by >> bh;
	for (int h = 0; h < bh; h++) {
		for (int y = 0; y < by; y++) {
			for (int x = 0; x < bx; x++) {
				cin >> box[h][y][x];
				int temp = box[h][y][x];
				if (temp == 0) cnt++;

				if (temp == 1) {
					q.push({ h,y,x });
					used[h][y][x] = 0;
				}
				else used[h][y][x] = -1;
			}
		}
	}
	return(cnt);
}

int main()
{
	if (input() == 0) {
		cout << 0;
		return (0);
	}
	
	int dh[6] = { 1,-1,0,0,0,0 };
	int dy[6] = { 0,0,-1,0,0,1 };
	int dx[6] = { 0,0,0,-1,1,0 };

	int cnt = 0, max = 0;
	while (!q.empty()) {
		s cur = q.front();
		q.pop();

		int temp = 0;
		for (int i = 0; i < 6; i++) {
			int nh = cur.h + dh[i];
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (nh < 0 || nh >= bh || ny < 0 || ny >= by || nx < 0 || nx >= bx) continue;
			if (box[nh][ny][nx] == -1 || used[nh][ny][nx] != -1) continue;
			temp = used[cur.h][cur.y][cur.x] + 1;
			used[nh][ny][nx] = temp;
			q.push({ nh,ny,nx });
		}
		if (max < temp) max = temp;
	}

	for (int h = 0; h < bh; h++) {
		for (int y = 0; y < by; y++) {
			for (int x = 0; x < bx; x++) {
				if (box[h][y][x] == 0 && used[h][y][x] == -1) {
					cout << -1;
					return (0);
				}
			}
		}
	}
	cout << max;

}
