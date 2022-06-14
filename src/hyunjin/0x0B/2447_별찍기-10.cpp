#include <iostream>
using namespace std;
char board[7000][7000];

void run(int by, int bx, int n) {
	if (n == 1) {
		board[by][bx] = '*';
		return;
	}

	n /= 3;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (y == 1 && x == 1) continue;
			run(by + n*y, bx + n*x, n);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	run(0, 0, n);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (board[y][x] == '*') cout << '*';
			else cout << ' ';
		}
		cout << "\n";
	}
}
