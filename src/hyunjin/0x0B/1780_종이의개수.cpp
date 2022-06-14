#include <iostream>
using namespace std;
int board[3000][3000];
int arr[3];

int same_num(int by, int bx, int k) {
	if (k == 1) return (1);

	for (int y = 0; y < k; y++) {
		for (int x = 0; x < k; x++) {
			if (board[by][bx] != board[by + y][bx + x]) return(0);
		}
	}
	return (1);
}

void run(int by, int bx, int k) {
	if (same_num(by, bx, k) == 1) { // 전부 같을 때 (k=1일 때 포함)
		arr[1 + board[by][bx]]++;
		return;
	}

	k /= 3;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			run(by + k * y, bx + k * x, k);
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
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << "\n";
	}
}
