#include <iostream>
using namespace std;
int board[100][100];

int check(int by, int bx, int n) {
	if (n == 1) return (1);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (board[by][bx] != board[by + y][bx + x]) return (0);
		}
	}
	return (1);
}

void run(int by, int bx, int n) {
	if (check(by, bx, n)) {
		cout << board[by][bx];
		return;
	}

	n /= 2;
	cout << "(";
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			run(by + n * y, bx + n * x, n);
		}
	}
	cout << ")";
}

int main()
{
	int n;
	cin >> n;
	string str;
	for (int y = 0; y < n; y++) {
		cin >> str;
		for (int x = 0; x < n; x++) {
			board[y][x] = str[x] - '0';
		}
	}

	run(0, 0, n);
}
