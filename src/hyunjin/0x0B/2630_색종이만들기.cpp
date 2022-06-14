#include <iostream>
using namespace std;
int board[200][200];
int arr[2];

int check(int a, int b, int n) {
	if (n == 1) return (1);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (board[a][b] != board[a + y][b + x]) return (0);
		}
	}
	return (1);
}

void run(int a, int b, int n) {
	if (check(a, b, n)) {
		arr[board[a][b]]++;
		return;
	}

	n /= 2;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			run(a + n * y, b + n * x, n);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> board[y][x];
		}
	}

	run(0, 0, n);
	cout << arr[0] << "\n" << arr[1];
}
