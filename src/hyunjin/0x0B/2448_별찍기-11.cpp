#include <iostream>
using namespace std;
int board[3072][6143];

void put_star(int by, int bx) {
	board[by][bx] = '*';
	board[by + 1][bx - 1] = '*';
	board[by + 1][bx + 1] = '*';
	for (int i = 0; i < 5; i++)
		board[by + 2][bx - 2 + i] = '*';
}

void run(int by, int bx, int n) {
	if (n == 3) {
		put_star(by, bx);
		return;
	}

	n /= 2;
	run(by, bx, n); // 1번 삼각형의 시작점
	run(by + n, bx - n, n); // 2번 삼각형의 시작점
	run(by + n, bx + n, n); // 3번 삼각형의 시작점
}

int main()
{
	int n;
	cin >> n;
	run(0, n - 1, n);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 2*n-1; x++) {
			if (board[y][x] == '*') cout << '*';
			else cout << ' ';
		}
		cout << "\n";
	}
}
